#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include <string>

class TextureManager {
public:
    // Ponto de acesso global
    static TextureManager& getInstance();

    // Método para simular uma ação
    void loadTexture(const std::string& name);

    // Impede cópia e atribuição do objeto
    TextureManager(const TextureManager&) = delete;
    TextureManager& operator=(const TextureManager&) = delete;

private:
    // Construtor privado: impede que usem "new TextureManager()"
    TextureManager();
};

#endif
