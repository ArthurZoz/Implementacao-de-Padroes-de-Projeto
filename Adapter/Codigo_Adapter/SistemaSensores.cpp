#include "SistemaSensores.h"
#include <iostream>

// --- Implementação do Adaptee (Hardware Legado) ---
double SensorFahrenheitLegado::obterLeituraFahrenheit() const {
    // Simula a leitura do hardware. 104°F equivale a 40°C.
    return 104.0; 
}

// --- Implementação do Adapter ---
AdaptadorSensor::AdaptadorSensor(const SensorFahrenheitLegado* sensor) 
    : sensorLegado_(sensor) {}

double AdaptadorSensor::getTemperaturaCelsius() const {
    // 1. Obtém a leitura no formato incompatível
    double fahrenheit = sensorLegado_->obterLeituraFahrenheit();
    
    std::cout << "[Adapter] Leitura recebida do hardware: " << fahrenheit << " F\n";
    std::cout << "[Adapter] Convertendo para Celsius...\n";
    
    // 2. Traduz os dados (fórmula de conversão térmica)
    double celsius = (fahrenheit - 32.0) * 5.0 / 9.0;
    
    // 3. Retorna o dado formatado para o sistema moderno
    return celsius;
}