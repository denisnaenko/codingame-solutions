#include <iostream>
#include <cmath>

using namespace std;

/* StringToFloat: Converts a string with comma-decimal
 * format into a double */
double StringToDouble(const string* posStr) {
    double result = 0.0;
    size_t i = 0;

    // Extract integer part
    while (posStr->at(i) != ',') {
        result = result * 10 + posStr->at(i) - '0';
        i++;
    }
    i++;  // skip comma

    double fraction = 0.0;
    double divisor = 1.0;

    // Extract decimal part
    while (i < posStr->size()) {
        fraction = fraction * 10 + (posStr->at(i) - '0');
        divisor *= 10;
        i++;
    }
    result += fraction / divisor;

    return result;
}

// DegToRad: Converts degrees to radians */
inline double DegToRad(double value) {
    return value * M_PI / 180.0;
}

/* CalcDistance: Calculates distance (in km) between
 * two geographic coordinates.
 */
double CalcDistance(double lonA, double lonB,
                    double latA, double latB) {
    lonA = DegToRad(lonA);
    lonB = DegToRad(lonB);
    latA = DegToRad(latA);
    latB = DegToRad(latB);

    constexpr double EarthRadiusKm = 6371.0;

    double x = (lonB - lonA) * cos((latA + latB) / 2.0);
    double y = latB - latA;

    return sqrt(x * x + y * y) * EarthRadiusKm;
}

/* ParseDefibInfo: extracts name, longitude and latitude
 * from a line in format: number;name;address;phone;longtitude;latitude
 */
void ParseDefibInfo(const string* defib,
                    string* defibName,
                    string* defibLonStr,
                    string* defibLatStr) {
    size_t i = 0;

    // Skip number
    while (i < defib->size() && defib->at(i) != ';') i++;
    i++;

    // Extract name
    while (i < defib->size() && defib->at(i) != ';') {
        defibName->push_back(defib->at(i));
        i++;
    }
    i++;

    // Skip address
    while (i < defib->size() && defib->at(i) != ';') i++;
    i++;

    // Skip Phone
    while (i < defib->size() && defib->at(i) != ';') i++;
    i++;

    // Extract longitude
    while (i < defib->size() && defib->at(i) != ';') {
        defibLonStr->push_back(defib->at(i));
        i++;
    }
    i++;

    // Extact latitude (until end of string)
    while (i < defib->size()) {
        defibLatStr->push_back(defib->at(i));
        i++;
    }
}

int main() {
    string userLonStr, userLatStr;
    int n;

    cin >> userLonStr; cin.ignore();
    cin >> userLatStr; cin.ignore();
    cin >> n; cin.ignore();

    double closestDistance = 0.0;
    string resultDefibName;

    for(int i = 0; i < n; i++) {
        string defib, defibName;
        string defibLonStr, defibLatStr;

        getline(cin ,defib);

        ParseDefibInfo(&defib, &defibName,
                       &defibLonStr, &defibLatStr);


        double userLon = StringToDouble(&userLonStr);
        double userLat = StringToDouble(&userLatStr);
        double defibLon = StringToDouble(&defibLonStr);
        double defibLat = StringToDouble(&defibLatStr);

        double currDistance = CalcDistance(userLon, defibLon,
                                           userLat, defibLat);

        if (i == 0 || currDistance < closestDistance) {
            closestDistance = currDistance;
            resultDefibName = defibName;
        }
    }

    cout << resultDefibName << endl;
    return 0;
}
