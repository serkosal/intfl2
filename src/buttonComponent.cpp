export module buttonComponent;

import ftxui;
import std;


export auto button_component(
    ftxui::App& app, 
    const std::string& name = "Anon"
) {
    return ftxui::Button(
        std::format("Hello, {}!", name), 
        app.ExitLoopClosure()
    );
}