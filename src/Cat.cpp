#include "Cat.hpp"

#include "Util/Input.hpp"

Cat::Cat()
    : m_Animation(std::make_shared<Util::Animation>(
          std::vector<std::string>{
              "../assets/sprites/cat/cat-0.bmp",
              "../assets/sprites/cat/cat-1.bmp",
              "../assets/sprites/cat/cat-2.bmp",
              "../assets/sprites/cat/cat-3.bmp",
              "../assets/sprites/cat/cat-4.bmp",
              "../assets/sprites/cat/cat-5.bmp",
              "../assets/sprites/cat/cat-6.bmp",
              "../assets/sprites/cat/cat-7.bmp",
          },
          false, 100, true, 200)) {
    m_Transform.translation = {-200, 200};
    SetDrawable(m_Animation);
}

void Cat::Update() {
    if (Util::Input::IsKeyPressed(Util::Keycode::A)) {
        m_Animation->Pause();
    }

    if (Util::Input::IsKeyPressed(Util::Keycode::S)) {
        m_Animation->Play();
    }
}
