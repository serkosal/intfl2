import std;

import ftxui;

import intfl.core;
import intfl.ui;
 
int main() {
  auto app = ftxui::App::FullscreenAlternateScreen();
  FileTree file_tree;

  app.Loop(ftxui_render(file_tree.root) | ftxui::frame);
  std::cout << std::endl;

  return 0;
}