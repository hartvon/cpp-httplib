#include <httplib.h>

int main(void)
{
  httplib::Server svr;

  svr.Get("/hi", [](const httplib::Request& /*req*/, httplib::Response& res) {
    res.set_content("Aloha world\n", "text/plain");
  });

  svr.listen("127.0.0.1", 8081);

  return 0;
}
