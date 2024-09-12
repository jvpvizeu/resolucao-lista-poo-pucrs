#include <iostream>

class CondicionadorAr {
private:
    int potencia; // Potência do condicionador de 0 a 10
    double temperaturaExterna; // Temperatura externa

public:
    // Construtor inicializa a potência e a temperatura externa
    CondicionadorAr() : potencia(0), temperaturaExterna(25.0) {}

    // Método para definir a potência do condicionador (0 a 10)
    void definirPotencia(int novaPotencia) {
        if (novaPotencia >= 0 && novaPotencia <= 10) {
            potencia = novaPotencia;
        } else {
            std::cout << "Potência inválida! Defina uma potência entre 0 e 10.\n";
        }
    }

    // Método para definir a temperatura externa
    void definirTemperaturaExterna(double tempExterna) {
        temperaturaExterna = tempExterna;
    }

    // Método para calcular a temperatura do ambiente
    double calcularTemperaturaAmbiente() const {
        double variacaoTemperatura = potencia * 1.8; // Cada unidade de potência diminui a temperatura em 1.8ºC
        return temperaturaExterna - variacaoTemperatura;
    }

    // Método para exibir a potência atual e a temperatura ambiente
    void exibirEstado() const {
        std::cout << "Potência: " << potencia << "/10" << std::endl;
        std::cout << "Temperatura externa: " << temperaturaExterna << "ºC" << std::endl;
        std::cout << "Temperatura ambiente resultante: " << calcularTemperaturaAmbiente() << "ºC\n";
    }
};

int main() {
    // Criando dois condicionadores
    CondicionadorAr condicionador1;
    CondicionadorAr condicionador2;

    // Configurando o primeiro condicionador com temperatura externa 25ºC e potência 5
    condicionador1.definirTemperaturaExterna(25.0);
    condicionador1.definirPotencia(5);

    // Configurando o segundo condicionador com temperatura externa 31ºC e potência máxima 10
    condicionador2.definirTemperaturaExterna(31.0);
    condicionador2.definirPotencia(10);

    // Exibindo os estados dos dois condicionadores
    std::cout << "Estado do Condicionador 1:\n";
    condicionador1.exibirEstado();

    std::cout << "\nEstado do Condicionador 2:\n";
    condicionador2.exibirEstado();

    return 0;
}