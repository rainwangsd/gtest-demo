#include "gtest/gtest.h"
#include "example.h"

#include <new>
#include <stdio.h>

#include <bits/stdc++.h>

#define DEBUG_TESTS          1
#if DEBUG_TESTS
#define INFO(msg) \
    fprintf(stderr, "INFO: %s,%s(),L%d: ", __FILE__, __FUNCTION__, __LINE__); \
    fprintf(stderr, "%s\n", msg);
#else
#define INFO(msg)
#endif

using namespace std;

int tests_compile_execute()
{
  char filename[100];
  cout << "Enter file name to compile ";
  cin.getline(filename, 100);

  // Build command to execute.  For example if the input
  // file name is a.cpp, then str holds "gcc -o a.out a.cpp"
  // Here -o is used to specify executable file name
  string str = "gcc ";
  str = str + " -o a.out " + filename;

  // Convert string to const char * as system requires
  // parameter of type const char *
  const char *command = str.c_str();

  cout << "Compiling file using " << command << endl;
  system(command);

  cout << "\nRunning file ";
  system("./a.out");

  return 0;
}

int tests_run_hello()
{
  cout << "Hello World!" << endl;

  const char *command = "ls";
  cout << "cmd: " << command << endl;
  // system("tdd_t_maint_v8");
  system(command);
  return 0;
}

// run tdd script
int tests_run_tdd()
{
  int ret = 0;

  cout << "tests: " << endl;

  const char *command = "tdd_t_maint_v8 ";
  cout << "cmd: " << command << endl;
  ret = system(command);

//   cout << "ret: " << ret << endl;
  return ret;
}

// test wled
// tdd/tools/tests/wled
int tests_run_tdd_wled()
{
  int ret = 0;


  cout << "tests: " << endl;
#if DEBUG_TESTS
  const char *command = "cd ../tdd/tools/tests/wled;tdd_t_maint_v8 ";
#else
  const char *command = "cd ../tdd/tools/tests/wled;tdd_t_maint_v8 > /dev/null ";
#endif
  cout << "cmd: " << command << endl;
  ret = system(command);

//   cout << "ret: " << ret << endl;
  return ret;
}

/**
 * test wled all
 *  - run tests
 *  - generate cpp tests call functions
 * tdd/tools/tests/wled
 *
*/
// wled tests

// std::string wled_tests[] = {
//   "help",
//   "t1s1_asku",
//   "t1s1_finddev   ",
//   "t1s1_ledpvoff  ",
//   "t1s1_ledpvon   ",
//   "t1s1_mcast     ",
//   "t1s1_settime   ",
//   "t1s1_synctime  "
// };

// int tests_run_tdd_wled_all()
// {
//   int ret = 0;

//   const char *tst_help = " wled tests all ";
//   cout << tst_help << endl;

//   string tst_cmd = "cd ../tdd/tools/tests/wled; ";
//   tst_cmd = tst_cmd + "tdd_t_maint_v8 ";

//   // TODO: FIXME, to add tests from arrary or test config file
//   // Declaring vector of string type for tests
//   vector<string> tests;
//   // Initialize vector with string using push_back
//   int tests_num = sizeof(wled_tests);
//   cout << "tests_num: " << tests_num << endl;

//   for (int i = 0; i < 1; i++) {
//     tests.push_back(wled_tests[i]);
//   }

//   //
//   for (int i = 0; i < tests.size(); i++) {
//     // Convert string to const char * for system call
//     string start_cmd = tst_cmd;
//     start_cmd += tests[i].c_str();
//     const char *command = start_cmd.c_str();
//     cout << "cmd: " << command << endl;
//     ret = system(command);
//     cout << "ret: " << ret << endl;
//   }
//   return ret;
// }

// Read tests from files
int tests_run_tdd_get_cases(string tests_file, vector<string> &tests)
{
  int ret = -1;

  const char *tst_help = " tests_run_tdd_get_cases ";
  cout << tst_help << endl;
  INFO("ENTRY");

  // TODO: FIXME, to add tests from config file
  // Declaring vector of string type for tests
  // vector<string> tests;
  int tests_num = 0;

  ifstream input;
  system("pwd");
  input.open(tests_file);
  if (input.fail()) {
    cout << "Error: no tests file existing!(" << tests_file << ")" << endl;
    // return ret;
  } else {
    string line_str;
    string token;

    // Initialize vector with string using push_back
    while (getline(input, line_str)) {
      int line_comment_flag = 0;
      stringstream in_line(line_str);
      int token_num = 0;
      while (in_line >> token) {
        // cout << "Here is a test: " << token << endl;
        // Check comment or test, #
        char test_flag = token.at(0);
        // cout << "test flag: " << test_flag << endl;
        if (test_flag == '#' && token_num == 0) {
          line_comment_flag = 1;
          break;
        }
#if DEBUG_TESTS
        cout << "Here is a test: " << token << endl;
#endif
        tests.push_back(token);
        token_num++;
        tests_num++;
        // only handle 1st token
        break;
      }
      if (line_comment_flag == 1) {
        continue; // skip the line with
      }
    }  // line_str
  }

#if DEBUG_TESTS
  cout << "### There are " << tests_num << " total tests." << endl;
#endif
  // display tests
  for (int i = 0; i < tests.size(); i++) {
    // Convert string to const char * for system call
    string start_cmd = tests[i].c_str();
    const char *command = start_cmd.c_str();
#if DEBUG_TESTS
    // cout << "cmd: " << command << endl;
    INFO(command);
#endif
    // ret = system(command);
    // cout << "ret: " << ret << endl;
  }

  INFO("EXIT");
  return ret;
}

// generate test cpp code
int tests_generate_code(string tst_cmd, vector<string> tests)
{
  INFO("ENTRY");

  string file_ouput = "./test/tests_wled.cpp";
  ofstream output;
  output.open(file_ouput);

  if (output.fail()) {
    cout << "Error to create tests file !(" << file_ouput << ")" << endl;
  } else {
    // Header and comment
    string str = "/* tests - wled, dynamic generated file from tool */ \n";
    // str += '\n';
    str += "#include \"gtest/gtest.h\" \n";
    str += "#include \"example.h\" \n";
    str += "\n";
    str += "#include <new> \n";
    str += "#include <stdio.h> \n";
    str += "\n";
    str += "#include <bits/stdc++.h> \n\n";
    str += "using namespace std; \n";
    output << str << endl;

    // TEST(example, tests_run_tdd_wled_all)
    // {
    //   int ret = 0;
    //   ret = tests_run_tdd_wled_all();
    //   ASSERT_EQ(ret, 0);
    //   // ASSERT_EQ(ret, 1);
    // }
    // Below is one example:
    // TEST(example, t1s1_asku) {
    //   int ret = 0;
    //   const char *command = "cd ../tdd/tools/tests/wled; tdd_t_maint_v8 t1s1_asku " ;
    //   ret = system(command);
    //   ASSERT_EQ(ret, 0);
    //   // ASSERT_EQ(ret, 1);
    // }

    for (int i = 0; i < tests.size(); i++) {
      string run_cmd = tst_cmd;
      str = "TEST(example, ";
      // Convert string to const char * for system call
      string start_cmd;
      start_cmd = tests[i].c_str();

      // run_cmd += " ";
      run_cmd += start_cmd;

      const char *command = run_cmd.c_str();
      cout << "cmd: " << command << endl;

      str += start_cmd;
      str += ") \n";
      str += "{ \n";

      str += "  int ret = 0; \n";
      // str += "  ret = tests_run_tdd_wled_all(); \n";
      str += "  const char *command = \"";
      // test cmd
      str += run_cmd.c_str();
      str += " \" ; \n";
      str += "  ret = system(command); \n";
      //   str += "  cout << \"ret: \" << ret << endl; \n";
      str += "  ASSERT_EQ(ret, 0); \n";
      str += "  // ASSERT_EQ(ret, 1); \n";
      str += "} \n";

      // Write to cpp file
      output << str << endl;
    }

    output.close();
  }

}

// Read tests from files
int tests_run_tdd_wled_all()
{
  int ret = -1;

  INFO("ENTRY");

#if DEBUG_TESTS
  const char *tst_help = " wled tests all ";
  cout << tst_help << endl;
#endif

  string tst_cmd = "cd ../tdd/tools/tests/wled; ";
  tst_cmd = tst_cmd + "tdd_t_maint_v8 ";

  // TODO: FIXME, to add tests from config file
  // Declaring vector of string type for tests
  vector<string> tests;

  ifstream input;
  string tests_file = "../tdd/tools/tests/wled/wled_tests.sh";
  system("pwd");
  ret = tests_run_tdd_get_cases(tests_file, tests);

  // run tests
  for (int i = 0; i < tests.size(); i++) {
    // Convert string to const char * for system call
    string start_cmd = tst_cmd;
    start_cmd += tests[i].c_str();
#if !DEBUG_TESTS
    start_cmd += " > /dev/null ";
#endif
    const char *command = start_cmd.c_str();
#if DEBUG_TESTS
    cout << "cmd: " << command << endl;
#endif
    ret = system(command);
#if DEBUG_TESTS
    // cout << "ret: " << ret << endl;
#endif
  }

  // generate cpp test file for (optional !!)
  tests_generate_code(tst_cmd, tests);

  INFO("EXIT");
  return ret;
}

/*
 * =========== TESTS ===========
 */

TEST(example, tests_run_hello)
{
  int ret = 0;
  ret = tests_run_hello();
  ASSERT_EQ(ret, 0);
  // ASSERT_EQ(ret, 1);
}

TEST(example, tests_run_tdd)
{
  int ret = 0;
  ret = tests_run_tdd();
  ASSERT_EQ(ret, 0);
  // ASSERT_EQ(ret, 1);
}

TEST(example, tests_run_tdd_wled)
{
  int ret = 0;
  ret = tests_run_tdd_wled();
  ASSERT_EQ(ret, 0);
  // ASSERT_EQ(ret, 1);
}

TEST(example, tests_run_tdd_wled_all)
{
  int ret = 0;
  ret = tests_run_tdd_wled_all();
  ASSERT_EQ(ret, 0);
  // ASSERT_EQ(ret, 1);
}
