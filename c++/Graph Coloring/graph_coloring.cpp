#include<iostream>
#include<vector>
#include<cstdlib>

typedef long long ll;

std::vector<std::vector<ll>>* adj;
std::vector<ll>* sol;
int n; // variable to store the number of vertices in the graph
int k; // the variable to store the number of colors
int s; // the variable to store the grid size
int count = 0; // variable to count solutions

void print_matrix(std::vector<ll>&);
/**
 * A function to color the graph according to the adjacency matrix
 *
 * @param y : starts at 0, it keeps track of vertices colored so far in the graph
 */
void color(int y) {
    if (y == n) {
        count++;// if a solution is found, increment the solution count

        /*
         * print the solution
         */
        std::cout << "Solution " << count << ": ";
        for (auto& f : *sol) {
            std::cout << f << " ";
        }
        std::cout << std::endl;

        /*
         * print the corresponding matrix
         */
        std::cout << "matrix: " << std::endl;
        print_matrix(*sol);
        return;
    }
    for (int j = 0; j < k; j++) {
        /*
         * to check if a vertex can be colored a certain color
         */
        bool possible = true;

        for (int l = 0; l < n; l++) {
            if ((*adj)[y][l] && (*sol)[l] == j) possible = false;
        }

        if (!possible) continue;

        (*sol)[y] = j; // color the yth vertex color j

        color(y + 1); // color the next vertex

        (*sol)[y] = -1; // backtrack
    }
}

/**
 * A function that prints the successful solution to the stdout as a matrix
 *
 * @param solution : a solution containing the color of each vertex
 */
void print_matrix(std::vector<ll>& solution) {
    for (int i = 0; i < s; i++) {
        for (int j = 0; j < s; j++) {
            if (i == j) {
                std::cout << 0 << "\t";
                continue;
            }
            int specific_k, cur_node_no;
            specific_k = j > i ? (i + 1) * (2 * (s - 1) - i) / 2 : (j + 1) * (2 * (s - 1) - j) / 2;
            cur_node_no = specific_k - std::abs(i - j);
            std::cout << solution[cur_node_no] + 1 << "\t";
        }
        std::cout << std::endl;
    }
}

/**
 *
 * @param grid : the grid size
 * @return : returns an adjacency matrix of the graph for a given grid size
 */
std::vector<std::vector<ll>> gen_adj(int grid) {
    std::vector<std::vector<ll>> new_adj((grid * (grid - 1) / 2), std::vector<ll>((grid * (grid - 1) / 2), 0));

    for (int i = 0; i < grid; i++) {
        for (int j = grid - 1; j > i; j--) {
            std::cout << std::endl;
            int cur_node_no = ((i + 1) * (2 * (grid - 1) - i) / 2) - std::abs(i - j);
            std::cout << cur_node_no << " attacks:" << std::endl << "in-column: ";
            int specific_k;
            int node_no;

            /*
             * register column neighbors
             */
            for (int f = i + 1; f < grid; f++) {
                if (f == j) continue;
                specific_k = j > f ? (f + 1) * (2 * (grid - 1) - f) / 2 : (j + 1) * (2 * (grid - 1) - j) / 2;
                node_no = specific_k - std::abs(f - j);
                std::cout << node_no << " ";

                new_adj[cur_node_no][node_no] = 1;
                new_adj[node_no][cur_node_no] = 1;
            }
            std::cout << std::endl << "in-row: ";

            /*
             * register row neighbors
             */
            for (int g = j - 1; g >= 0; g--) {
                if (g == i) continue;
                specific_k = g > i ? (i + 1) * (2 * (grid - 1) - i) / 2 : (g + 1) * (2 * (grid - 1) - g) / 2;
                node_no = specific_k - std::abs(i - g);
                std::cout << node_no << " ";

                new_adj[cur_node_no][node_no] = 1;
                new_adj[node_no][cur_node_no] = 1;
            }
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
    return new_adj;
}

int main() {
    s = 5; // set the grid size to an even number
    n = s * (s - 1) / 2; // compute the vertices that will be in the graph
    k = s - 1; // the colors to grid size - 1

    sol = new std::vector<ll>(n, -1); // initialize the solution of colors to -1s
    adj = new std::vector<std::vector<ll>>(gen_adj(s)); // generate the adjacency matrix for the given grid size

    std::cout << "Adjacency table:" << std::endl; // print the adjacency table
    for (int p = n - 1; p >= 0; p--) {
        for (int q = 0; q < n; q++) {
            std::cout << (*adj)[p][q] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    color(0); // color the graph

    delete sol; // free dynamically allocated memory
    delete adj; // free dynamically allocated memory

    return 0;
}
