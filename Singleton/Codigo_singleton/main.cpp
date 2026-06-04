#include "TextureManager.h"
#include <iostream>

int main() {
    std::cout << "--- Inicio do Programa ---\n\n";

    // 1. Acessando pela primeira vez (o construtor será executado aqui)
    std::cout << "Acessando pela primeira vez:\n";
    TextureManager& gerador1 = TextureManager::getInstance();
    gerador1.loadTexture("player.png");
    std::cout << "Endereco de memoria do gerador1: " << &gerador1 << "\n\n";

    // 2. Acessando pela segunda vez (o construtor nao será executado de novo)
    std::cout << "Acessando pela segunda vez:\n";
    TextureManager& gerador2 = TextureManager::getInstance();
    gerador2.loadTexture("enemy.png");
    std::cout << "Endereco de memoria do gerador2: " << &gerador2 << "\n\n";

    // 3. Se os endereços forem iguais, é o mesmo objeto.
    if (&gerador1 == &gerador2) {
        std::cout << "!! gerador1 e gerador2 sao o MESMO objeto !!\n";
    }

    return 0;
}
