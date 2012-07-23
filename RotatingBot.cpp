#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
using namespace std;
static const double EPS = 1e-5;
typedef long long ll;


class RotatingBot {
public:
    int minArea( vector <int> moves )
    {
        int x = 0;
        int y = 0;
        
        int max_x = moves[0];
        int max_y = 0;
        int min_x = 0;
        int min_y = 0;
        
        // direction
        int d_x[] = { 1, 0, -1, 0 };
        int d_y[] = { 0, 1, 0, -1 };
        
        typedef pair<int, int> point;
        
        point p;
        set<point> s;
        s.insert( make_pair(0, 0) );
        
        for( int i = 0; i < moves.size(); i++ )
        {
            int move = moves[i];

            if( i == 1 )
                max_y = moves[1];
            
            if( i == 2 )
                min_x = min( 0, moves[0] - moves[2] );
            
            if( i == 3 )
                min_y = min( 0, moves[1] - moves[3] );
            
            while( move-- )
            {
                x += d_x[i % 4];
                y += d_y[i % 4];
                
                point next = make_pair(x, y);
                
                if( s.count(next) != 0 )
                    return -1;
                
                s.insert(next);
                
            }
            
            if( x > max_x || x < min_x || y > max_y || y < min_y )
                return -1;
            
            if( ( x == max_x || x == min_x ) && ( y == max_y || y == min_y ) )
            {
                // OK
            }
            else
            {
                point next = make_pair(x + d_x[i % 4], y + d_y[i % 4]);
                if( s.count(next) != 0 )
                {
                    // OK
                }
                else
                {
                    if( i == moves.size() - 1 )
                    {
                        
                    }
                    else
                    {
                        return -1;
                    }
                }
            }
            
        }
        
        return ( max_x - min_x + 1 ) * ( max_y - min_y + 1 );
    }
};

// BEGIN CUT HERE
namespace moj_harness {
    int run_test_case(int);
    void run_test(int casenum = -1, bool quiet = false) {
        if (casenum != -1) {
            if (run_test_case(casenum) == -1 && !quiet) {
                cerr << "Illegal input! Test case " << casenum << " does not exist." << endl;
            }
            return;
        }
        
        int correct = 0, total = 0;
        for (int i=0;; ++i) {
            int x = run_test_case(i);
            if (x == -1) {
                if (i >= 100) break;
                continue;
            }
            correct += x;
            ++total;
        }
        
        if (total == 0) {
            cerr << "No test cases run." << endl;
        } else if (correct < total) {
            cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << endl;
        } else {
            cerr << "All " << total << " tests passed!" << endl;
        }
    }
    
    int verify_case(int casenum, const int &expected, const int &received, clock_t elapsed) { 
        cerr << "Example " << casenum << "... "; 
        
        string verdict;
        vector<string> info;
        char buf[100];
        
        if (elapsed > CLOCKS_PER_SEC / 200) {
            sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
            info.push_back(buf);
        }
        
        if (expected == received) {
            verdict = "PASSED";
        } else {
            verdict = "FAILED";
        }
        
        cerr << verdict;
        if (!info.empty()) {
            cerr << " (";
            for (int i=0; i<(int)info.size(); ++i) {
                if (i > 0) cerr << ", ";
                cerr << info[i];
            }
            cerr << ")";
        }
        cerr << endl;
        
        if (verdict == "FAILED") {
            cerr << "    Expected: " << expected << endl; 
            cerr << "    Received: " << received << endl; 
        }
        
        return verdict == "PASSED";
    }
    
    int run_test_case(int casenum) {
        switch (casenum) {
            case 0: {
                int moves[]               = {1,2,3,4,5};
                int expected__            = -1;
                
                clock_t start__           = clock();
                int received__            = RotatingBot().minArea(vector <int>(moves, moves + (sizeof moves / sizeof moves[0])));
                return verify_case(casenum, expected__, received__, clock()-start__);
            }
            case 1: {
                int moves[]               = {3,10};
                int expected__            = 44;
                
                clock_t start__           = clock();
                int received__            = RotatingBot().minArea(vector <int>(moves, moves + (sizeof moves / sizeof moves[0])));
                return verify_case(casenum, expected__, received__, clock()-start__);
            }
            case 2: {
                int moves[]               = {1,1,1,1};
                int expected__            = -1;
                
                clock_t start__           = clock();
                int received__            = RotatingBot().minArea(vector <int>(moves, moves + (sizeof moves / sizeof moves[0])));
                return verify_case(casenum, expected__, received__, clock()-start__);
            }
            case 3: {
                int moves[]               = {9,5,11,10,11,4,10};
                int expected__            = 132;
                
                clock_t start__           = clock();
                int received__            = RotatingBot().minArea(vector <int>(moves, moves + (sizeof moves / sizeof moves[0])));
                return verify_case(casenum, expected__, received__, clock()-start__);
            }
            case 4: {
                int moves[]               = {12,1,27,14,27,12,26,11,25,10,24,9,23,8,22,7,21,6,20,5,19,4,18,3,17,2,16,1,15};
                int expected__            = 420;
                
                clock_t start__           = clock();
                int received__            = RotatingBot().minArea(vector <int>(moves, moves + (sizeof moves / sizeof moves[0])));
                return verify_case(casenum, expected__, received__, clock()-start__);
            }
            case 5: {
                int moves[]               = {8,6,6,1};
                int expected__            = -1;
                
                clock_t start__           = clock();
                int received__            = RotatingBot().minArea(vector <int>(moves, moves + (sizeof moves / sizeof moves[0])));
                return verify_case(casenum, expected__, received__, clock()-start__);
            }
            case 6: {
                int moves[]               = {8,6,6};
                int expected__            = 63;
                
                clock_t start__           = clock();
                int received__            = RotatingBot().minArea(vector <int>(moves, moves + (sizeof moves / sizeof moves[0])));
                return verify_case(casenum, expected__, received__, clock()-start__);
            }
            case 7: {
                int moves[]               = {5,4,5,3,3};
                int expected__            = 30;
                
                clock_t start__           = clock();
                int received__            = RotatingBot().minArea(vector <int>(moves, moves + (sizeof moves / sizeof moves[0])));
                return verify_case(casenum, expected__, received__, clock()-start__);
            }
                
                // custom cases
                
                /*      case 8: {
                 int moves[]               = ;
                 int expected__            = ;
                 
                 clock_t start__           = clock();
                 int received__            = RotatingBot().minArea(vector <int>(moves, moves + (sizeof moves / sizeof moves[0])));
                 return verify_case(casenum, expected__, received__, clock()-start__);
                 }*/
                /*      case 9: {
                 int moves[]               = ;
                 int expected__            = ;
                 
                 clock_t start__           = clock();
                 int received__            = RotatingBot().minArea(vector <int>(moves, moves + (sizeof moves / sizeof moves[0])));
                 return verify_case(casenum, expected__, received__, clock()-start__);
                 }*/
                /*      case 10: {
                 int moves[]               = ;
                 int expected__            = ;
                 
                 clock_t start__           = clock();
                 int received__            = RotatingBot().minArea(vector <int>(moves, moves + (sizeof moves / sizeof moves[0])));
                 return verify_case(casenum, expected__, received__, clock()-start__);
                 }*/
            default:
                return -1;
        }
    }
}


int main(int argc, char *argv[])
{
    moj_harness::run_test(0);
    return 0;
    
    if (argc == 1) {
        moj_harness::run_test();
    } else {
        for (int i=1; i<argc; ++i)
            moj_harness::run_test(atoi(argv[i]));
    }
}
// END CUT HERE
