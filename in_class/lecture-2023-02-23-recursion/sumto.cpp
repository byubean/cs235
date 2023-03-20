#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::istream;
using std::vector;

class Grid {
private:
    vector<int> _grid;
    int NR, NC, NL;
    int _index(int row, int col, int lev) {
        return lev * NR * NC + row * NC + col;
    }
public:
    int get(int row, int col, int lev) {
        return _grid[_index(row, col, lev)];
    }
    /* etc. */
    friend istream& operator >>(istream &ins, Grid& grid) {
        ins >> grid.NR >> grid.NC >> grid.NL;
        int value;
        for (int i = 0; i < grid.NR * grid.NC * grid.NL; i++) {
            ins >> value;
            grid._grid.push_back(value);
        }
        return ins;
    }
};

int sumto(int x) {
    cout << x << endl;
    if (x < 0) { throw std::invalid_argument("X must be positive"); }
    if (x == 0) { return 0; }

    return x + sumto(x - 1);
}

int main(int argc, char *argv[]) {
    cout << sumto(atoi(argv[1])) << endl;
}
