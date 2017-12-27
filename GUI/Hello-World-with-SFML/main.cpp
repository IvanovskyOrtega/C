// Bibliotecas necesarias
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

// Compilar con: g++ main.cpp -lsfml-graphics -lsfml-audio -lsfml-system -lsfml-window

using namespace sf; // Para sf::

int main()
{

    // Se crea una instancia de la ventana principal
    RenderWindow window(sf::VideoMode(800, 600), "Hello SFML");

    // Cargamos una imagen para mostrar en pantalla
    Texture texture;
    if (!texture.loadFromFile("Resources/earth.jpg"))
        return EXIT_FAILURE;
    Sprite sprite(texture);
    // Escalamos la imagen
    sprite.setScale(0.5,0.5);
    
    // Creamos texto grafico a mostrar
    Font font;
    if (!font.loadFromFile("Resources/arial.ttf"))
        return EXIT_FAILURE;
    Text text("Hello SFML", font, 50);
    
    // Cargamos musica a reproducir
    Music music;
    if (!music.openFromFile("Resources/8bitEvangelion.ogg"))
        return EXIT_FAILURE;
    // Reproducimos la musica
    music.play();
    
    // Se muestra la pantalla
    while (window.isOpen())
    {
        
        // Se procesan los eventos
        Event event;
        while (window.pollEvent(event))
        {
           
            // Se cierra la ventana
            if (event.type == Event::Closed)
                window.close();

        }

        // Limpiar la pantalla
        window.clear();

        // Se dibuja el grafico
        window.draw(sprite);

        // Se dibuja el texto
        window.draw(text);

        // Se actualiza la ventana
        window.display();

    }

    return EXIT_SUCCESS;
}