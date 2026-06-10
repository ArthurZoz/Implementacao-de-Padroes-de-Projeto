#include <iostream>
#include "StreamingEventos.h"

int main() {
    std::cout << "=== Inicializando Servidores de Streaming ===\n";

    // 1. Criamos o nosso Sujeito (Publisher)
    CanalYoutube* canalTech = new CanalYoutube("Mundo Tech");

    // 2. Criamos os Observadores (Subscribers)
    UsuarioYoutube* alice = new UsuarioYoutube("Alice");
    UsuarioYoutube* bob = new UsuarioYoutube("Bob");
    UsuarioYoutube* carlos = new UsuarioYoutube("Carlos");

    // 3. Montamos a malha de assinaturas dinamicamente
    canalTech->inscrever(alice);
    canalTech->inscrever(bob);
    canalTech->inscrever(carlos);

    // 4. Primeiro Evento: Disparará notificação para os 3 usuários
    canalTech->publicarVideo("C++ Avançado: Dominando Ponteiros!");

    // 5. Cancelamento de inscrição em tempo de execução
    std::cout << "\n-- Carlos desativou o sininho de notificacoes --\n";
    canalTech->desinscrever(carlos);

    // 6. Segundo Evento: Apenas Alice e Bob devem reagir agora
    canalTech->publicarVideo("Padroes de Projeto na Pratica.");

    // Gerenciamento de memória limpa
    delete canalTech;
    delete alice;
    delete bob;
    delete carlos;

    return 0;
}