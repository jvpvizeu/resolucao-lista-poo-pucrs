#include <iostream>

class Carro {
private:
    double tanqueCombustivel; // Quantidade de combustível no tanque em litros
    double distanciaPercorrida; // Distância total percorrida em km
    const double consumoPorKm = 15.0; // Consumo do carro em km por litro (15 km/l)
    const double capacidadeTanque = 50.0; // Capacidade máxima do tanque (50 litros)

public:
    // Construtor: inicializa o tanque de combustível vazio e distância percorrida a zero
    Carro() : tanqueCombustivel(0), distanciaPercorrida(0) {}

    // Método para abastecer o carro
    void abastecer(double litros) {
        if (litros > 0) {
            tanqueCombustivel += litros;
            if (tanqueCombustivel > capacidadeTanque) {
                tanqueCombustivel = capacidadeTanque; // Limita ao máximo do tanque
                std::cout << "O tanque está cheio. Sobrou combustível que não coube.\n";
            }
        } else {
            std::cout << "Quantidade de combustível inválida!\n";
        }
    }

    // Método para mover o carro por uma distância em km
    void mover(double distancia) {
        if (distancia > 0) {
            double combustivelNecessario = distancia / consumoPorKm;

            if (combustivelNecessario <= tanqueCombustivel) {
                // Se houver combustível suficiente, move o carro
                distanciaPercorrida += distancia;
                tanqueCombustivel -= combustivelNecessario;
            } else {
                // Caso não tenha combustível suficiente, move até onde pode
                double distanciaPossivel = tanqueCombustivel * consumoPorKm;
                distanciaPercorrida += distanciaPossivel;
                tanqueCombustivel = 0; // O tanque fica vazio
                std::cout << "Combustível insuficiente! O carro percorreu apenas " << distanciaPossivel << " km.\n";
            }
        } else {
            std::cout << "Distância inválida!\n";
        }
    }

    // Método para retornar a quantidade de combustível no tanque
    double consultarCombustivel() const {
        return tanqueCombustivel;
    }

    // Método para retornar a distância total percorrida
    double consultarDistanciaPercorrida() const {
        return distanciaPercorrida;
    }
};

int main() {
    // Criando dois carros
    Carro carro1;
    Carro carro2;

    // Abastecendo 20 litros no primeiro carro e 30 litros no segundo carro
    carro1.abastecer(20);
    carro2.abastecer(30);

    // Movendo o primeiro carro por 200 km e o segundo carro por 400 km
    carro1.mover(200);
    carro2.mover(400);

    // Exibindo o combustível restante e a distância percorrida para cada carro
    std::cout << "Carro 1:\n";
    std::cout << "Combustível restante: " << carro1.consultarCombustivel() << " litros\n";
    std::cout << "Distância percorrida: " << carro1.consultarDistanciaPercorrida() << " km\n\n";

    std::cout << "Carro 2:\n";
    std::cout << "Combustível restante: " << carro2.consultarCombustivel() << " litros\n";
    std::cout << "Distância percorrida: " << carro2.consultarDistanciaPercorrida() << " km\n";

    return 0;
}