// Lab6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

int main()
{
    string background = "images1/backgrounds/winter.png";
    string foreground = "images1/characters/Rey_green_screen.png";

    Texture backgroundTex;
    if (!backgroundTex.loadFromFile(background)) {
        cout << "Couldn't Load Image" << endl;
        exit(1);
    }
    Texture foregroundTex;
    if (!foregroundTex.loadFromFile(foreground)) {
        cout << "Couldn't Load Image" << endl;
        exit(1);
    }

    Image backgroundImage;
    backgroundImage = backgroundTex.copyToImage();
    Image foregroundImage;
    foregroundImage = foregroundTex.copyToImage();

    Color corner = foregroundImage.getPixel(0, 0);

    Vector2u sz = backgroundImage.getSize();
    for (int y = 0; y < sz.y; y++) {
        for (int x = 0; x < sz.x; x++) {
            Color example = foregroundImage.getPixel(x, y);
            if (example == corner) {
                foregroundImage.setPixel(x, y, backgroundImage.getPixel(x, y)); 
            }
        }
    }

    RenderWindow window(VideoMode(1024, 768), "Here's the output");
    Sprite sprite1;
    Texture tex1;
    tex1.loadFromImage(foregroundImage);
    sprite1.setTexture(tex1);
    window.clear();
    window.draw(sprite1);
    window.display();
    while (true);
     
}

