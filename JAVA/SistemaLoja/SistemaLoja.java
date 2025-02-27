import java.io.*;
import java.util.*;

class Produto implements Serializable {
    private int id;
    private String nome;
    private double preco;
    private int estoque;

    public Produto(int id, String nome, double preco, int estoque) {
        this.id = id;
        this.nome = nome;
        this.preco = preco;
        this.estoque = estoque;
    }

    public int getId() { return id; }
    public String getNome() { return nome; }
    public double getPreco() { return preco; }
    public int getEstoque() { return estoque; }

    public void ajustarEstoque(int quantidade) {
        this.estoque += quantidade;
    }

    @Override
    public String toString() {
        return String.format("ID: %d | Nome: %s | Preço: R$ %.2f | Estoque: %d", id, nome, preco, estoque);
    }
}

class Cliente implements Serializable {
    private int id;
    private String nome;
    private String telefone;

    public Cliente(int id, String nome, String telefone) {
        this.id = id;
        this.nome = nome;
        this.telefone = telefone;
    }

    public int getId() { return id; }
    public String getNome() { return nome; }
    public String getTelefone() { return telefone; }

    @Override
    public String toString() {
        return String.format("ID: %d | Nome: %s | Telefone: %s", id, nome, telefone);
    }
}

class Venda implements Serializable {
    private int id;
    private Cliente cliente;
    private List<Produto> produtos;
    private double total;

    public Venda(int id, Cliente cliente) {
        this.id = id;
        this.cliente = cliente;
        this.produtos = new ArrayList<>();
        this.total = 0.0;
    }

    public void adicionarProduto(Produto produto, int quantidade) {
        if (produto.getEstoque() >= quantidade) {
            produto.ajustarEstoque(-quantidade);
            produtos.add(produto);
            total += produto.getPreco() * quantidade;
        } else {
            throw new IllegalArgumentException("Estoque insuficiente para o produto: " + produto.getNome());
        }
    }

    public double getTotal() { return total; }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(String.format("Venda ID: %d\nCliente: %s\nProdutos:\n", id, cliente.getNome()));
        for (Produto p : produtos) {
            sb.append(p.getNome()).append("\n");
        }
        sb.append(String.format("Total: R$ %.2f", total));
        return sb.toString();
    }
}

public class SistemaLoja {
    private static List<Produto> produtos = new ArrayList<>();
    private static List<Cliente> clientes = new ArrayList<>();
    private static List<Venda> vendas = new ArrayList<>();

    private static void salvarDados() throws IOException {
        try (ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream("dados_loja.dat"))) {
            oos.writeObject(produtos);
            oos.writeObject(clientes);
            oos.writeObject(vendas);
        }
    }

    @SuppressWarnings("unchecked")
    private static void carregarDados() throws IOException, ClassNotFoundException {
        try (ObjectInputStream ois = new ObjectInputStream(new FileInputStream("dados_loja.dat"))) {
            produtos = (List<Produto>) ois.readObject();
            clientes = (List<Cliente>) ois.readObject();
            vendas = (List<Venda>) ois.readObject();
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); 

        try {
            carregarDados();
        } catch (IOException | ClassNotFoundException e) {
            System.out.println("Iniciando com novos dados...");
        }

        while (true) {
            System.out.println("\n--- Sistema de Loja ---");
            System.out.println("1. Cadastrar Produto");
            System.out.println("2. Cadastrar Cliente");
            System.out.println("3. Realizar Venda");
            System.out.println("4. Relatório de Vendas");
            System.out.println("5. Listar Produtos");
            System.out.println("6. Listar Clientes");
            System.out.println("0. Sair");
            System.out.print("Escolha uma opção: ");
            int opcao = scanner.nextInt();

            switch (opcao) {
                case 1 -> {
                    System.out.print("ID do Produto: ");
                    int id = scanner.nextInt();
                    scanner.nextLine(); // Consumir quebra de linha
                    System.out.print("Nome do Produto: ");
                    String nome = scanner.nextLine();
                    System.out.print("Preço do Produto: ");
                    double preco = scanner.nextDouble();
                    System.out.print("Estoque Inicial: ");
                    int estoque = scanner.nextInt();
                    produtos.add(new Produto(id, nome, preco, estoque));
                    System.out.println("Produto cadastrado com sucesso!");
                }
                case 2 -> {
                    System.out.print("ID do Cliente: ");
                    int id = scanner.nextInt();
                    scanner.nextLine(); // Consumir quebra de linha
                    System.out.print("Nome do Cliente: ");
                    String nome = scanner.nextLine();
                    System.out.print("Telefone do Cliente: ");
                    String telefone = scanner.nextLine();
                    clientes.add(new Cliente(id, nome, telefone));
                    System.out.println("Cliente cadastrado com sucesso!");
                }
                case 3 -> {
                    System.out.print("ID do Cliente: ");
                    int idCliente = scanner.nextInt();
                    Cliente cliente = clientes.stream()
                            .filter(c -> c.getId() == idCliente)
                            .findFirst()
                            .orElse(null);
                    if (cliente == null) {
                        System.out.println("Cliente não encontrado!");
                        break;
                    }

                    Venda venda = new Venda(vendas.size() + 1, cliente);
                    while (true) {
                        System.out.print("ID do Produto (ou -1 para finalizar): ");
                        int idProduto = scanner.nextInt();
                        if (idProduto == -1) break;

                        Produto produto = produtos.stream()
                                .filter(p -> p.getId() == idProduto)
                                .findFirst()
                                .orElse(null);

                        if (produto == null) {
                            System.out.println("Produto não encontrado!");
                            continue;
                        }

                        System.out.print("Quantidade: ");
                        int quantidade = scanner.nextInt();
                        try {
                            venda.adicionarProduto(produto, quantidade);
                            System.out.println("Produto adicionado à venda."); 
                        } catch (IllegalArgumentException e) {
                            System.out.println(e.getMessage());
                        }
                    }
                    vendas.add(venda);
                    System.out.println("Venda realizada com sucesso!");
                }
                case 4 -> vendas.forEach(System.out::println);
                case 5 -> produtos.forEach(System.out::println);
                case 6 -> clientes.forEach(System.out::println);
                case 0 -> {
                    try {
                        salvarDados();
                        System.out.println("Dados salvos com sucesso!");
                    } catch (IOException e) {
                        System.out.println("Erro ao salvar dados: " + e.getMessage());
                    }
                    System.out.println("Saindo...");
                    System.exit(0);
                }
                default -> System.out.println("Opção inválida!");
            }
        }
    }
}