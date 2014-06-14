#include <map>
#include <string>
#include <fstream>
#include <streambuf>
#include <curl/curl.h>
#include <fcntl.h>
#include "http_transmitter.hh"
#include "answer.pb.h"
#include "problem.pb.h"

using namespace std;

int main()
{
  curl_global_init(CURL_GLOBAL_ALL);

  // POST problem
  HttpTransmitter tx( "http://localhost:5000/problem" );
  std::ifstream pb_file( "test.problem", ios::binary );
  std::string str((std::istreambuf_iterator<char>(pb_file)),
                   std::istreambuf_iterator<char>());
  string response = tx.make_post_request( str );
  printf( "POST respone was %s\n", response.c_str() );

  // GET answer
  map<string, string> headers;
  headers["problem_id"] = response;
  response = tx.make_get_request( headers );
  AnswerBuffers::Outcome outcome;
  outcome.ParseFromString( response );
  printf( "GET response from the server is %s\n", outcome.DebugString().c_str() );

  curl_global_cleanup();
  return 0;
}