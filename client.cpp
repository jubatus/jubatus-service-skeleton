#include <iostream>

#include "kvs_client.hpp"
#include "kvs_types.hpp"

using namespace std;

const string HOST = "localhost";
const int    PORT = 9199;
const string NAME = "";

int main(int argc, char* argv[]){
    jubatus::client::kvs c(HOST, PORT, NAME, 5);

    cout << c.put("apple",  "pomme") << endl;
    cout << c.put("orange", "orangé") << endl;
    cout << c.put("banana", "banane") << endl;
    cout << c.put("strawberry", "fraise") << endl;
    cout << c.put("unknown", "???") << endl;
    cout << c.del("unknown") << endl;

    try {
        cout << c.get("apple") << endl;
        cout << c.get("orange") << endl;
        cout << c.get("banana") << endl;
        cout << c.get("strawberry") << endl;
        cout << c.get("unknown") << endl;
    } catch (const runtime_error& e) {
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}
