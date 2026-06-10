#include <iostream>
#include "SistemaSensores.h"

// Função Cliente: Representa o painel de controle do seu sistema.
// Ela aceita apenas objetos do tipo 'SensorTemperatura'.
void exibirNoPainel(const SensorTemperatura* sensor) {
    std::cout << "Painel de Controle -> Temperatura Atual: " 
              << sensor->getTemperaturaCelsius() << " C\n";
}

int main() {
    std::cout << "--- Iniciando Painel Industrial ---\n\n";

    // 1. Instanciamos o dispositivo legado (incompatível)
    SensorFahrenheitLegado* sensorAntigo = new SensorFahrenheitLegado();

    // 2. Colocamos o dispositivo legado "dentro" do nosso adaptador
    SensorTemperatura* sensorAdaptado = new AdaptadorSensor(sensorAntigo);

    // 3. O painel interage com o adaptador como se fosse um sensor nativo
    exibirNoPainel(sensorAdaptado);

    delete sensorAdaptado;
    delete sensorAntigo;

    return 0;
}