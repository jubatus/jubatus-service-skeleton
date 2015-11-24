#include <iostream>
#include <string>

#include "kvs_client.hpp"
#include "kvs_types.hpp"

using namespace std;

const string HOST = "localhost";
const int    PORT = 9199;
const string NAME = "test";

int main(int argc, char* argv[]) {
  jubatus::client::kvs c(HOST, PORT, NAME, 5);

  cout << c.put("key1", 20) << endl;
  cout << c.put("key2", -5) << endl;
  cout << c.put("key3", 5) << endl;

  cout << c.get("key2").value << endl;

  cout << c.get_average() << endl;

  return 0;
}
