#ifndef STREAMING_EVENTOS_H
#define STREAMING_EVENTOS_H

#include <string>
#include <vector>

// -------------------------------------------------------------------
// OBSERVER INTERFACE: A interface que qualquer interessado deve herdar.
// -------------------------------------------------------------------
class InterfaceInscrito {
public:
    virtual ~InterfaceInscrito() = default;
    
    // Método abstrato que o Sujeito chamará para entregar a novidade
    virtual void atualizar(const std::string& nomeCanal, const std::string& tituloVideo) = 0;
};

// -------------------------------------------------------------------
// SUBJECT (PUBLISHER): O objeto monitorado que gerencia as assinaturas.
// -------------------------------------------------------------------
class CanalYoutube {
private:
    std::vector<InterfaceInscrito*> inscritos_; // Lista abstrata de observadores
    std::string nomeCanal_;
    std::string ultimoVideoPublicado_;

public:
    CanalYoutube(const std::string& nome);
    
    // Funções de gerenciamento de assinaturas (Contrato do Observer)
    void inscrever(InterfaceInscrito* inscrito);
    void desinscrever(InterfaceInscrito* inscrito);
    void notificarInscritos();

    // Lógica de negócio do canal
    void publicarVideo(const std::string& titulo);
};

// -------------------------------------------------------------------
// CONCRETE OBSERVER: A classe real que reagirá ao evento.
// -------------------------------------------------------------------
class UsuarioYoutube : public InterfaceInscrito {
private:
    std::string nomeUsuario_;

public:
    UsuarioYoutube(const std::string& nome);
    
    // Implementação da reação ao receber a notificação
    void atualizar(const std::string& nomeCanal, const std::string& tituloVideo) override;
};

#endif // STREAMING_EVENTOS_H