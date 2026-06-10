#include "StreamingEventos.h"
#include <iostream>
#include <algorithm>

// --- Implementação do Canal do YouTube (Subject) ---
CanalYoutube::CanalYoutube(const std::string& nome) : nomeCanal_(nome) {}

void CanalYoutube::inscrever(InterfaceInscrito* inscrito) {
    inscritos_.push_back(inscrito);
}

void CanalYoutube::desinscrever(InterfaceInscrito* inscrito) {
    // Remove o inscrito da lista de ponteiros usando algoritmos padrão do C++
    inscritos_.erase(std::remove(inscritos_.begin(), inscritos_.end(), inscrito), inscritos_.end());
}

void CanalYoutube::notificarInscritos() {
    // Varre todos os observadores cadastrados notificando-os do evento
    for (InterfaceInscrito* inscrito : inscritos_) {
        inscrito->atualizar(nomeCanal_, ultimoVideoPublicado_);
    }
}

void CanalYoutube::publicarVideo(const std::string& titulo) {
    ultimoVideoPublicado_ = titulo;
    std::cout << "\n[Canal " << nomeCanal_ << "] Publicou um novo video: \"" << titulo << "\"\n";
    
    // O evento aconteceu! Hora de avisar os interessados de forma automática
    notificarInscritos();
}

// --- Implementação do Usuário (Concrete Observer) ---
UsuarioYoutube::UsuarioYoutube(const std::string& nome) : nomeUsuario_(nome) {}

void UsuarioYoutube::atualizar(const std::string& nomeCanal, const std::string& tituloVideo) {
    // O que o usuário faz quando o vídeo sai (relação de causa e efeito)
    std::cout << "-> Notificacao no celular de [" << nomeUsuario_ << "]: O canal '" 
              << nomeCanal << "' postou \"" << tituloVideo << "\"!\n";
}