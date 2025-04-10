#include <iostream>
#include "vektor.h"
#include "ritkavektor.h"

using namespace std;  

int main() {
    try {
        Vektor<int> v1(5); 
        int arr[] = { 1, 2, 3, 4, 5 };
        Vektor<int> v2(arr, 5); 

        Vektor<int> v3 = v1 + v2;
        Vektor<int> v4 = v2 - v1;
        double skalarSzorzat = v1 * v2;
        double norm = ~v2;
        double distance = v1 % v2;

        cout << "v1 + v2 : ";
        for (int i = 0; i < 5; ++i) {
            cout << v3[i] << " ";
        }
        cout << "\n";

        cout << "v2 - v1 : ";
        for (int i = 0; i < 5; ++i) {
            cout << v4[i] << " ";
        }
        cout << "\n";

        cout << "skalarszorzat (v1 * v2): " << skalarSzorzat << "\n";
        cout << "norma (~v2): " << norm << "\n";
        cout << "tavolsag (v1 % v2): " << distance << "\n";

        RitkaVektor<int> rv1(5); 
        RitkaVektor<int> rv2(arr, 5); 

        RitkaVektor<int> rv3 = rv1 + rv2;
        RitkaVektor<int> rv4 = rv2 - rv1;
        double rvSkalarSzorzat = rv1 * rv2;
        double rvNorm = ~rv2;
        double rvDistance = rv1 % rv2;

        cout << "RitkaVektor (rv1 + rv2) : ";
        for (int i = 0; i < 5; ++i) {
            cout << rv3[i] << " ";
        }
        cout << "\n";

        cout << "RitkaVektor (rv2 - rv1) : ";
        for (int i = 0; i < 5; ++i) {
            cout << rv4[i] << " ";
        }
        cout << "\n";

        cout << "RitkaVektor skalarszorzat (rv1 * rv2) : " << rvSkalarSzorzat << "\n";
        cout << "RitkaVektor norma (~rv2): " << rvNorm << "\n";
        cout << "RitkaVektor tavolsag (rv1 % rv2): " << rvDistance << "\n";

        Vektor<int> v_from_rv = static_cast<Vektor<int>>(rv2);
        RitkaVektor<int> rv_from_v = static_cast<RitkaVektor<int>>(v2);

        cout << "Vektor --> RitkaVektor (rv2) : ";
        for (int i = 0; i < 5; ++i) {
            cout << v_from_rv[i] << " ";
        }
        cout << "\n";

        cout << "RitkaVektor --> Vektor (v2) : ";
        for (int i = 0; i < 5; ++i) {
            cout << rv_from_v[i] << " ";
        }
        cout << "\n";

    }
    catch (const char* msg) {
        cerr << "Error: " << msg << "\n";
    }

    return 0;
}
