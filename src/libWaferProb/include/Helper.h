#ifndef _WaferProbe_helper_H_
#define _WaferProbe_helper_H_

#include <string>
#include <vector>

using namespace std;

// define some global code.
#define DEFAULT_ZABER_POS -3
#define DEFAULT_Z_POS 0
#define DEFAULT_BAD_XY_POS -101

namespace WaferProb{
    void tokenizeString(const string& str, char delim, vector<string>& tokens);
    string toUpper(const string& str);
    int axis_number(const string& axis_str);
}

#endif
