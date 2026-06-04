#include "TextureManager.h"
#include <iostream>

// Retorna a única instância existente na memória
TextureManager& TextureManager::getInstance() {
    static TextureManager instance;
    return instance;
}

// Construtor privado
TextureManager::TextureManager() {
    std::cout << "[CONSTRUTOR] Instancia criada na memoria!\n";
}

void TextureManager::loadTexture(const std::string& name) {
    std::cout << "Carregando textura: " << name << "\n";
}
