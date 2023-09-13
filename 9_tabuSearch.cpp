#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>

double objectiveFunction(const std::vector<int>& solution) {
    double value = 0.0;
    for (int val : solution) {
        value += val * val;
    }
    return value;
}

struct Solution {
    std::vector<int> solution;
    double cost;
};

Solution generateRandomSolution(int numVariables) {
    Solution initialSolution;
    initialSolution.solution.resize(numVariables);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(-100, 100);

    for (int& val : initialSolution.solution) {
        val = dist(gen);
    }

    initialSolution.cost = objectiveFunction(initialSolution.solution);
    return initialSolution;
}

Solution performNeighborhoodSearch(const Solution& currentSolution) {
    Solution newSolution = currentSolution;

    return newSolution;
}

int main() {
    const int numVariables = 10;
    const int maxIterations = 100;
    const int tabuListSize = 10;

    Solution currentSolution = generateRandomSolution(numVariables);
    Solution bestSolution = currentSolution;
    std::vector<Solution> tabuList;

    for (int iteration = 0; iteration < maxIterations; ++iteration) {
        currentSolution = performNeighborhoodSearch(currentSolution);

        if (currentSolution.cost < bestSolution.cost) {
            bestSolution = currentSolution;
        }

        tabuList.push_back(currentSolution);

        if (tabuList.size() > tabuListSize) {
            tabuList.erase(tabuList.begin());
        }
    }

    std::cout << "Best solution found: ";
    for (int val : bestSolution.solution) {
        std::cout << val << " ";
    }
    std::cout << "\nBest cost: " << bestSolution.cost << std::endl;

    return 0;
}
