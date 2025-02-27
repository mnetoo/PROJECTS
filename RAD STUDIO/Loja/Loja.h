//---------------------------------------------------------------------------

#ifndef LojaH
#define LojaH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.Grids.hpp>
#include <vector>
#include <System.hpp>  // Necessário para o tipo String no RAD Studio
#include <System.DateUtils.hpp> // Necessário para funções de data/hora

using namespace std;



//CLASSE



using namespace std;

class Produto
{
private:
    String nome;
    float preco;
    int quantidade;

public:
    // Construtor padrão
    Produto() : nome(L""), preco(0.0f), quantidade(0) {}

    // Construtor com parâmetros
    Produto(const String& nome, float preco, int quantidade)
        : nome(nome), preco(preco), quantidade(quantidade) {}

    // Métodos para obter os valores
    String getNome() const { return nome; }
    float getPreco() const { return preco; }
    int getQuantidade() const { return quantidade; }

    // Métodos para definir os valores
    void setNome(const String& n) { nome = n; }
    void setPreco(float p) { preco = p; }
    void setQuantidade(int q) { quantidade = q; }
};

class Pedido
{
private:
	vector<Produto> produtos;
	float total;
	String cliente;

public:
	// Construtor padrão e com parâmetros
	Pedido() : total(0.0f) {}
	Pedido(const vector<Produto>& produtos, float total, const String& cliente)
		: produtos(produtos), total(total), cliente(cliente) {}

	// Getters
	vector<Produto> getProdutos() const
    {
		return produtos;
	}

	float getTotal() const
	{
		return total;
	}

	String getCliente () const
	{
		return cliente;
	}

	// Setters
	void setProdutos(const vector<Produto>& produtos)
	{
		this->produtos = produtos;
    }

	void setTotal(float total)
    {
		this->total = total;
	}

	void setCliente(String cliente)
	{
        this->cliente = cliente;
	}
};

class Estoque
{
private:
    vector<Produto> estoque;

public:
    // Construtor padrão e com parâmetros
    Estoque() {}
    Estoque(const vector<Produto>& estoque)
        : estoque(estoque) {}

    // Getter
    vector<Produto> getProdutos() const
    {
        return estoque;
    }

    // Setter
    void setProdutos(const vector<Produto>& estoque)
    {
        this->estoque = estoque;
    }
};




class Cliente
{
private:
	String nome;     // Usando "String" para compatibilidade com RAD Studio
    String cpf;      // CPF armazenado como String
    int idade;       // Idade como inteiro
    String telefone; // Telefone como String

public:
    // Construtor padrão
    Cliente() : nome(L""), cpf(L""), idade(0), telefone(L"") {}

    // Construtor com parâmetros
    Cliente(const String& nome, const String& cpf, int idade, const String& telefone)
        : nome(nome), cpf(cpf), idade(idade), telefone(telefone) {}

    // Getters
    String getNome() const { return nome; }
    String getCpf() const { return cpf; }
    int getIdade() const { return idade; }
    String getTelefone() const { return telefone; }

    // Setters
    void setNome(const String& nome) { this->nome = nome; }
    void setCpf(const String& cpf) { this->cpf = cpf; }
    void setIdade(int idade) { this->idade = idade; }
    void setTelefone(const String& telefone) { this->telefone = telefone; }
};






//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TTabSheet *TabSheet3;
	TBitBtn *BitBtn1;
	TBitBtn *BitBtn2;
	TBitBtn *BitBtn3;
	TBitBtn *BitBtn4;
	TTabSheet *TabSheet7;
	TLabel *Label1;
	TEdit *Edit1;
	TLabel *Label2;
	TEdit *Edit2;
	TBitBtn *BitBtn5;
	TLabel *Label3;
	TEdit *Edit3;
	TStringGrid *StringGrid1;
	TTabSheet *TabSheet2;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TEdit *Edit4;
	TEdit *Edit5;
	TDateTimePicker *DateTimePicker1;
	TEdit *Edit6;
	TBitBtn *BitBtn6;
	TStringGrid *StringGrid2;
	TComboBox *ComboBox1;
	TLabel *Label8;
	TEdit *Edit7;
	TEdit *Edit8;
	TEdit *Edit9;
	TLabel *Label9;
	TComboBox *ComboBox2;
	TEdit *Edit10;
	TEdit *Edit11;
	TEdit *Edit12;
	TLabel *Label10;
	TLabel *Label11;
	TBitBtn *BitBtn8;
	TBitBtn *BitBtn7;
	TStringGrid *StringGrid3;
	TEdit *Edit13;
	TLabel *Label12;
	TLabel *Label13;
	TBitBtn *BitBtn9;
	TLabel *Label14;
	TLabel *Label15;
	TLabel *Label16;
	TBitBtn *BitBtn10;
	TEdit *Edit14;
	TLabel *Label17;
	TStringGrid *StringGrid4;
	TEdit *Edit15;
	TLabel *Label18;
	TBitBtn *BitBtn11;
	TBitBtn *BitBtn12;
	TBitBtn *BitBtn13;
	void __fastcall BitBtn1Click(TObject *Sender);
	void __fastcall BitBtn2Click(TObject *Sender);
	void __fastcall BitBtn3Click(TObject *Sender);
	void __fastcall BitBtn4Click(TObject *Sender);
	void __fastcall BitBtn5Click(TObject *Sender);
	void __fastcall BitBtn6Click(TObject *Sender);
	void __fastcall BitBtn7Click(TObject *Sender);
	void __fastcall BitBtn8Click(TObject *Sender);
	void __fastcall ComboBox1Change(TObject *Sender);
	void __fastcall ComboBox2Change(TObject *Sender);
	void __fastcall Edit12Change(TObject *Sender);
	void __fastcall BitBtn9Click(TObject *Sender);
	void __fastcall BitBtn11Click(TObject *Sender);
	void __fastcall BitBtn10Click(TObject *Sender);
	void __fastcall BitBtn12Click(TObject *Sender);
	void __fastcall BitBtn13Click(TObject *Sender);
private:	// User declarations
	vector<Produto> produtosPedidos;
    vector<Pedido> pedidos;
	vector<Produto> estoque;
	vector<Cliente> clientes;
	float soma = 0;
    int lastProcessedRow = 0;
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
