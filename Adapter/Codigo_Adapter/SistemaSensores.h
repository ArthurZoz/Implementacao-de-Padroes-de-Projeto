#ifndef SISTEMA_SENSORES_H
#define SISTEMA_SENSORES_H

// 1. Target (Alvo): A interface que o sistema moderno usa.
class SensorTemperatura {
public:
    virtual ~SensorTemperatura() = default;
    
    // O sistema moderno espera receber a temperatura em Celsius
    virtual double getTemperaturaCelsius() const = 0;
};


// 2. Adaptee (Adaptado): A classe legada incompatível.
class SensorFahrenheitLegado {
public:
    // Esta classe só fornece Fahrenheit. Não possui o método esperado.
    double obterLeituraFahrenheit() const;
};

// 3. Adapter (Adaptador): O tradutor que une os dois mundos.
class AdaptadorSensor : public SensorTemperatura {
private:
    const SensorFahrenheitLegado* sensorLegado_;

public:
    // O adaptador recebe o objeto incompatível no construtor
    AdaptadorSensor(const SensorFahrenheitLegado* sensor);

    // Sobrescreve o método alvo para realizar a adaptação
    double getTemperaturaCelsius() const override;
};

#endif