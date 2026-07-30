export module intfl.ui.components;

import std;

import ftxui;

using namespace ftxui;

export Component MyCollapsible(
    ConstStringRef label, 
    Component child,
    Ref<bool> show,
    Color fg_color = Color::White
) {
    class Impl : public ComponentBase {
      public:
        Impl(
            ConstStringRef label, 
            Component child, 
            Ref<bool> show,
            Color fg_color
        ) : show_(show) {
            CheckboxOption opt;
            opt.transform = [fg_color](EntryState s) {
                // auto prefix = text(s.state ? "▼ " : "▶ ");
                auto t = text(s.label) | color(fg_color);
                if (s.active) {
                t |= bold;
                }
                if (s.focused) {
                t |= inverted;
                }
                return t;
                // return hbox({prefix, t});
            };
            Add(Container::Vertical({
                Checkbox(std::move(label), show_.operator->(), opt),
                Maybe(std::move(child), show_.operator->()),
            }));
        }
        
        Ref<bool> show_;
    };

  return Make<Impl>(std::move(label), std::move(child), show, fg_color);
}