#include <iostream>
#include <cmath> // Para a função sqrt (raiz quadrada) e M_PI (constante pi)

class Circulo {
private:
    double raio;
    double centroX;
    double centroY;

    // Método privado para calcular a área do círculo
    double calcularArea() const {
        return M_PI * raio * raio;
    }

    // Método privado para calcular a circunferência do círculo
    double calcularCircunferencia() const {
        return 2 * M_PI * raio;
    }

    // Método privado para calcular a distância entre os centros de 2 círculos
    double calcularDistancia(const Circulo& outroCirculo) const {
        double deltaX = outroCirculo.centroX - centroX;
        double deltaY = outroCirculo.centroY - centroY;
        return std::sqrt(deltaX * deltaX + deltaY * deltaY);
    }

public:
    // Construtor para inicializar o círculo com raio 0 e centro na origem
    Circulo() : raio(0), centroX(0), centroY(0) {}

    // Método público para definir o raio
    void definirRaio(double novoRaio) {
        if (novoRaio > 0) {
            raio = novoRaio;
        } else {
            std::cout << "O raio deve ser positivo!\n";
        }
    }

    // Método público para aumentar o raio em um percentual
    void aumentarRaio(double percentual) {
        if (percentual > 0) {
            raio += raio * (percentual / 100.0);
        } else {
            std::cout << "O percentual deve ser positivo!\n";
        }
    }

    // Método público para definir o centro do círculo
    void definirCentro(double x, double y) {
        centroX = x;
        centroY = y;
    }

    // Método público para imprimir o raio
    void imprimirRaio() const {
        std::cout << "Raio: " << raio << std::endl;
    }

    // Método público para imprimir o centro do círculo
    void imprimirCentro() const {
        std::cout << "Centro: (" << centroX << ", " << centroY << ")" << std::endl;
    }

    // Método público para imprimir a área do círculo
    void imprimirArea() const {
        std::cout << "Área: " << calcularArea() << std::endl;
    }

    // Método público para calcular e imprimir a distância entre os centros de 2 círculos
    void imprimirDistancia(const Circulo& outroCirculo) const {
        std::cout << "Distância entre os centros: " << calcularDistancia(outroCirculo) << " unidades\n";
    }
};

int main() {
    // Criando dois objetos da classe Circulo
    Circulo circulo1;
    Circulo circulo2;

    // Definindo o raio e o centro do primeiro círculo
    circulo1.definirRaio(10);
    circulo1.definirCentro(0, 0);

    // Definindo o raio e o centro do segundo círculo
    circulo2.definirRaio(5);
    circulo2.definirCentro(3, 4);

    // Imprimindo as informações do primeiro círculo
    std::cout << "Círculo 1:\n";
    circulo1.imprimirRaio();
    circulo1.imprimirCentro();
    circulo1.imprimirArea();

    // Imprimindo as informações do segundo círculo
    std::cout << "\nCírculo 2:\n";
    circulo2.imprimirRaio();
    circulo2.imprimirCentro();
    circulo2.imprimirArea();

    // Aumentando o raio do segundo círculo em 20%
    circulo2.aumentarRaio(20);
    std::cout << "\nApós aumentar o raio do Círculo 2 em 20%:\n";
    circulo2.imprimirRaio();
    circulo2.imprimirArea();

    // Calculando e imprimindo a distância entre os centros dos dois círculos
    std::cout << "\nDistância entre os centros dos círculos:\n";
    circulo1.imprimirDistancia(circulo2);

    return 0;
}
