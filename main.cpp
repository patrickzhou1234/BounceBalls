#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <Windows.h>

using namespace sf;

int main()
{
    HWND hWnd = GetConsoleWindow();
    ShowWindow( hWnd, SW_HIDE );
    RenderWindow window(VideoMode(VideoMode::getDesktopMode().width, VideoMode::getDesktopMode().height), "SFML Project", Style::Fullscreen);
    ShowWindow(window.getSystemHandle(), SW_MAXIMIZE);
    Clock clock;
    CircleShape shape(50);
    shape.setFillColor(Color(0, 166, 146));
    shape.setOutlineThickness(10.f);
    shape.setOutlineColor(Color(250, 150, 100));
    int circleposY=0,circleposX=0;
    bool circleY=true, circleX=true;

    Sound mus;
    SoundBuffer buf;
    mus.setBuffer(buf);
    if(!buf.loadFromFile("./boing.ogg")) {
        return -1;
    }

    window.clear(Color::Black);
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == Event::Closed)
                window.close();
        }

        if (clock.getElapsedTime().asSeconds()>0.001f) {
            if (circleposY==VideoMode::getDesktopMode().height-110) {
                circleY=false;
                mus.play();
            }
            if (circleposX==VideoMode::getDesktopMode().width-110) {
                circleX=false;
                mus.play();
            }
            if (circleposX==10) {
                circleX=true;
                mus.play();
            }
            if (circleposY==10) {
                circleY=true;
                mus.play();
            }
            if (circleX) {
                circleposX++;
            } else {
                circleposX--;
            }
            if (circleY) {
                circleposY++;
            } else {
                circleposY--;
            }
            shape.setPosition(circleposX, circleposY);
            clock.restart();
        }
        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}