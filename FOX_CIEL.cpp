#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    // Mapping polyhedron names to their respective face counts
    unordered_map<string, int> faces = {
        {"Tetrahedron", 4},
        {"Cube", 6},
        {"Octahedron", 8},
        {"Dodecahedron", 12},
        {"Icosahedron", 20}
    };

    int n, total_faces = 0;
    cin >> n;  // Read number of polyhedrons

    string polyhedron;
    for (int i = 0; i < n; i++) {
        cin >> polyhedron;  // Read the polyhedron name
        total_faces += faces[polyhedron];  // Add corresponding faces
    }

    cout << total_faces << endl;  // Output the total number of faces
    return 0;
}
