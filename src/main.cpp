import ftxui;
 
using ftxui::App;
using ftxui::Button;
using ftxui::Component;
 
int main() {
  App app = App::TerminalOutput();
  Component button = Button("Click me", app.ExitLoopClosure());
  app.Loop(button);
  return 0;
}