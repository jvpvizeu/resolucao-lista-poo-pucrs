#include <iostream>
#include <string>

class Pessoa {
/* Encapsulamento => Perceba que os membros private só podem ser acessados dentro da própria classe*/
private:
    std::string nome;
    int idade;
    float altura;

/* Repare que métodos que interagem com o usuário precisam estar em public */
public:
    // Definindo o construtor com parametros
    Pessoa(std::string nome, int idade, float altura) {
    }
    
    // Métodos ¨Set¨ -> Gravar informacao
    void setNome(std::string nome) {
        this->nome = nome;
    }

    void setIdade(int idade) {
        this->idade = idade;
    }

    void setAltura(float altura) {
        this->altura = altura;
    }

    // Métodos ¨Get¨ -> Obter informacao
    std::string getNome() const {
        return nome;
    }

    int getIdade() const {
        return idade;
    }

    float getAltura() const {
        return altura;
    }

    // Método para imprimir os dados da pessoa
    void imprimirDados() const {
        std::cout << "Nome: " << nome << "\n";
        std::cout << "Idade: " << idade << " anos\n";
        std::cout << "Altura: " << altura << " metros\n";
    }
};

int main() {
    // Criando um objeto Pessoa
    Pessoa pessoa1("João", 25, 1.75);

    // Imprimindo os dados da pessoa
    pessoa1.imprimirDados();

    // Alterando os dados da pessoa
    pessoa1.setNome("Maria");
    pessoa1.setIdade(30);
    pessoa1.setAltura(1.68);

    // Imprimindo os novos dados da pessoa
    std::cout << "\nApós alterar os dados:\n";
    pessoa1.imprimirDados();

    return 0;
}