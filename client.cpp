#include <iostream>

#include "kvs_client.hpp"
#include "kvs_types.hpp"

using namespace std;

const string HOST = "localhost";
const int    PORT = 9199;
const string NAME = "";

int main(int argc, char* argv[]){
    jubatus::client::kvs c(HOST, PORT, 5);

    cout << c.put(NAME, "apple",  "pomme") << endl;
    cout << c.put(NAME, "orange", "orangé") << endl;
    cout << c.put(NAME, "banana", "banane") << endl;
    cout << c.put(NAME, "strawberry", "fraise") << endl;
    cout << c.put(NAME, "unknown", "???") << endl;
    cout << c.del(NAME, "unknown") << endl;

    try {
        cout << c.get(NAME, "apple") << endl;
        cout << c.get(NAME, "orange") << endl;
        cout << c.get(NAME, "banana") << endl;
        cout << c.get(NAME, "strawberry") << endl;
        cout << c.get(NAME, "unknown") << endl;
    } catch (const runtime_error& e) {
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}
