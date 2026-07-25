import buttonComponent;
import appComponent;
 
int main() {
  auto app = app_component();
  auto button = button_component(app, "Sergey");
  app.Loop(button);
  return 0;
}