//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Loja.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
    // Página Inicial
	this->PageControl1->ActivePageIndex = 0;

    // Indexadores Coluna estoque
	StringGrid1->Cells[0][0] = "NOME";
	StringGrid1->Cells[1][0] = "PREÇO";
	StringGrid1->Cells[2][0] = "QUANTIDADE";

	// Indexadores Coluna Clientes
	StringGrid2->Cells[0][0] = "NOME";
	StringGrid2->Cells[1][0] = "CPF";
	StringGrid2->Cells[2][0] = "IDADE";
	StringGrid2->Cells[3][0] = "TELEFONE";

	// Indexadores Coluna Venda
	StringGrid3->Cells[0][0] = "PRODUTO";
	StringGrid3->Cells[1][0] = "PREÇO UNITÁRIO";
	StringGrid3->Cells[2][0] = "QUANTIDADE";
	StringGrid3->Cells[3][0] = "TOTAL";

	// Indexadores Coluna Histórico
	StringGrid4->Cells[0][0] = "PRODUTO";
	StringGrid4->Cells[1][0] = "PREÇO UNITÁRIO";
	StringGrid4->Cells[2][0] = "QUANTIDADE";
	StringGrid4->Cells[3][0] = "TOTAL";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn1Click(TObject *Sender)
{
    this->PageControl1->ActivePageIndex = 0;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn2Click(TObject *Sender)
{
    this->PageControl1->ActivePageIndex = 1;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn3Click(TObject *Sender)
{
    this->PageControl1->ActivePageIndex = 2;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn4Click(TObject *Sender)
{
	this->PageControl1->ActivePageIndex = 3;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn5Click(TObject *Sender)
{
	if (Edit1->Text == "" && Edit2->Text == "" && Edit3->Text == "")
	{
		ShowMessage("Por favor, preencha todos os campos!");
	}
	else
	{
		Produto produto(Edit1->Text, StrToFloat(Edit2->Text), StrToInt(Edit3->Text));
		estoque.push_back(produto);

		// Adicionar os dados do produto na StringGrid
		int rowIndex = StringGrid1->RowCount; // Posição para nova linha
		StringGrid1->RowCount = rowIndex + 1; // Aumenta o número de linhas

		StringGrid1->Cells[0][rowIndex] = Edit1->Text;
		StringGrid1->Cells[1][rowIndex] = "R$" + FormatFloat("0.00", StrToFloat(Edit2->Text));
		StringGrid1->Cells[2][rowIndex] = IntToStr(StrToInt(Edit3->Text));

		Edit1->Clear();
		Edit2->Clear();
		Edit3->Clear();

		// Atualizar o ComboBox com os nomes dos produtos cadastrados
		ComboBox2->Items->Clear();
		for (size_t i = 0; i < estoque.size(); i++)
		{
			ComboBox2->Items->Add(estoque[i].getNome()); // Adiciona o nome do cliente no ComboBox
		}

		this->PageControl1->ActivePageIndex = 1;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn6Click(TObject *Sender)
{
	if (Edit4->Text == "" && Edit5->Text == "" && Edit6->Text == "")
	{
		ShowMessage("Por favor, preencha todos os campos!");
	}
	else
	{
		 // Calcula a Idade
        TDateTime dataNascimento = DateTimePicker1->Date;
        TDateTime dataAtual = Date();
        int idade = YearsBetween(dataAtual, dataNascimento);

        // Cria o cliente e o adiciona à lista
		Cliente cliente(Edit4->Text, Edit5->Text, idade, Edit6->Text);
		clientes.push_back(cliente);

		// Adicionar os dados do produto na StringGrid
		int rowIndex = StringGrid2->RowCount; // Posição para nova linha
		StringGrid2->RowCount = rowIndex + 1; // Aumenta o número de linhas

		StringGrid2->Cells[0][rowIndex] = Edit4->Text;
		StringGrid2->Cells[1][rowIndex] = Edit5->Text;
		StringGrid2->Cells[2][rowIndex] = IntToStr(idade) + " anos";
		StringGrid2->Cells[3][rowIndex] = Edit6->Text;

		Edit4->Clear();
		Edit5->Clear();
		Edit6->Clear();
		DateTimePicker1->Date = Now();

		// Atualizar o ComboBox com os nomes dos clientes cadastrados
		ComboBox1->Items->Clear();
		for (size_t i = 0; i < clientes.size(); i++)
		{
			ComboBox1->Items->Add(clientes[i].getNome()); // Adiciona o nome do cliente no ComboBox
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn7Click(TObject *Sender)
{
    this->PageControl1->ActivePageIndex = 2;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn8Click(TObject *Sender)
{
    this->PageControl1->ActivePageIndex = 0;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ComboBox1Change(TObject *Sender)
{
    // Verifica se há algo selecionado no ComboBox
    String nomeSelecionado = ComboBox1->Text;
    if (nomeSelecionado.IsEmpty())
        return; // Se não houver nome selecionado, nada será feito

    // Procurar o cliente correspondente
    for (int i = 0; i < clientes.size(); i++)
    {
        // Se encontrar o cliente com o nome selecionado
        if (clientes[i].getNome() == nomeSelecionado)
        {
            // Preencher os campos Edit7, Edit8 e Edit9 com as informações do cliente
            Edit7->Text = clientes[i].getCpf();       // Preencher CPF no Edit7
            Edit8->Text = IntToStr(clientes[i].getIdade()); // Preencher idade no Edit8
            Edit9->Text = clientes[i].getTelefone();  // Preencher telefone no Edit9
            break; // Saímos do loop após encontrar o cliente
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ComboBox2Change(TObject *Sender)
{
    // Verifica se há algo selecionado no ComboBox de produtos
    String nomeProdutoSelecionado = ComboBox2->Text;
    if (nomeProdutoSelecionado.IsEmpty())
        return; // Se não houver nome selecionado, nada será feito

    // Procurar o produto correspondente
    for (int i = 0; i < estoque.size(); i++)
    {
        // Se encontrar o produto com o nome selecionado
        if (estoque[i].getNome() == nomeProdutoSelecionado)
        {
            // Preencher os campos Edit10 e Edit11 com as informações do produto
			Edit10->Text = FloatToStrF(estoque[i].getPreco(), ffFixed, 8, 2);  // Preencher preço no Edit10
            Edit11->Text = IntToStr(estoque[i].getQuantidade());              // Preencher quantidade no Edit11
            break; // Saímos do loop após encontrar o produto
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit12Change(TObject *Sender)
{
	 // Converter valores dos campos
	 float valor1 = StrToFloat(Edit10->Text);
	 float quantidadeDesejada = StrToFloat(Edit12->Text);
	 float total = (valor1 * quantidadeDesejada);

	 if ( StrToInt(Edit12->Text) > StrToInt(Edit11->Text) )
	 {
		ShowMessage("Quantidade deseja superior ao disponível no estoque!");
		Edit13->Text = "";
	 }

	 // Calcular e atribuir o total
	 Edit13->Text = FormatFloat("0.00", total);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::BitBtn9Click(TObject *Sender)
{
	String produto = ComboBox2->Text;
	float preco = StrToFloat(Edit10->Text);
	int qntdDes = StrToInt(Edit12->Text);
	float total = StrToFloat(Edit13->Text);


	 // Adicionar uma nova linha ao StringGrid
	int rowIndex = StringGrid3->RowCount; // Posição para nova linha
	StringGrid3->RowCount = rowIndex + 1; // Aumenta o número de linhas

	// Inserir os valores nas colunas correspondentes
	StringGrid3->Cells[0][rowIndex] = produto;
	StringGrid3->Cells[1][rowIndex] = FormatFloat("0.00", preco);
	StringGrid3->Cells[2][rowIndex] = qntdDes;
	StringGrid3->Cells[3][rowIndex] = FormatFloat("0.00", total);


	// Atualizar o estoque
	for (size_t i = 0; i < estoque.size(); i++)
	{
		if (estoque[i].getNome() == produto)
		{
			// Atualiza o estoque
			estoque[i].setQuantidade(estoque[i].getQuantidade() - StrToInt(Edit12->Text));

			// Criar o produto do pedido atual
			Produto produtoPedido(produto, preco, qntdDes);
			produtosPedidos.push_back(produtoPedido);
			produtoPedido.setPreco(total);
			break;
		}
	}

	// Itera apenas a partir da última linha processada
    for (int rowIndex = lastProcessedRow + 1; rowIndex < StringGrid3->RowCount; rowIndex++)
    {
        // Verifica se a célula não está vazia antes de converter para float
        if (!StringGrid3->Cells[3][rowIndex].IsEmpty())
        {
			soma += StringGrid3->Cells[3][rowIndex].ToDouble();
        }
	}
	// Atualiza a última linha processada
	lastProcessedRow = StringGrid3->RowCount - 1;

	Edit10->Clear();
	Edit11->Clear();
	Edit12->Clear();
	Edit13->Clear();
	Edit14->Text = FormatFloat("0.00", soma);

     // Preencher a StringGrid com os dados do estoque
    StringGrid1->RowCount = 1; // Resetar as linhas (mantém o cabeçalho)

    for (size_t i = 0; i < estoque.size(); i++)
    {
		int rowIndex = StringGrid1->RowCount; // Posição para nova linha
		StringGrid1->RowCount = rowIndex + 1; // Aumentar o número de linhas

		// Preencher as células da linha
        StringGrid1->Cells[0][rowIndex] = estoque[i].getNome();
		StringGrid1->Cells[1][rowIndex] = "R$" + FormatFloat("0.00", estoque[i].getPreco());
		StringGrid1->Cells[2][rowIndex] = estoque[i].getQuantidade();
    }

}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn11Click(TObject *Sender)
{
    String cliente = Edit15->Text;

    // Percorre todos os pedidos
    for (size_t i = 0; i < pedidos.size(); i++)
    {
		if (cliente == pedidos[i].getCliente()) // Verifica se o cliente corresponde
		{
            const auto& produtos = pedidos[i].getProdutos();
            // Para cada produto no pedido
            for (size_t j = 0; j < produtos.size(); j++)
            {
                int rowIndex = StringGrid4->RowCount; // Posição da nova linha
				StringGrid4->RowCount = rowIndex + 1; // Aumenta o número de linhas

                // Preenche as informações na linha correspondente
				StringGrid4->Cells[0][rowIndex] = produtos[j].getNome();         // Nome do produto
				StringGrid4->Cells[1][rowIndex] = FormatFloat("0.00", produtos[j].getPreco());        // Preço unitário
				StringGrid4->Cells[2][rowIndex] = produtos[j].getQuantidade();   // Quantidade solicitada
                StringGrid4->Cells[3][rowIndex] = FormatFloat("0.00", produtos[j].getPreco() * produtos[j].getQuantidade()); // Total do produto
            }
		}
		else
		{
			ShowMessage("Não existe pedido para o cliente.");
            return;
		}
	}

	Edit15->Clear();
}


//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn10Click(TObject *Sender)
{
	// Verifica se existem produtos no pedido
    if (produtosPedidos.empty())
    {
        ShowMessage("Nenhum produto foi adicionado ao pedido!");
        return;
	}


    // Cria o pedido e associa ao cliente selecionado
    String cliente = ComboBox1->Text;
	Pedido pedido(produtosPedidos, soma, cliente);

    // Adiciona o pedido na lista de pedidos
    pedidos.push_back(pedido);

    // Mensagem de sucesso
    ShowMessage("Pedido finalizado com sucesso!");

    // Limpa os produtos do pedido atual para um novo pedido
	produtosPedidos.clear();

	this->PageControl1->ActivePageIndex = 4;

	Edit7->Clear();
	Edit8->Clear();
	Edit9->Clear();
	Edit10->Clear();
	Edit11->Clear();
	Edit12->Clear();
	Edit13->Clear();
	Edit14->Clear();

	 // Reseta a StringGrid para apenas o cabeçalho
	StringGrid3->RowCount = 1; // Apenas uma linha (geralmente usada para cabeçalho)
	// Opcional: Limpa os textos do cabeçalho, se necessário
	for (int col = 0; col < StringGrid3->ColCount; col++)
	{
		// Indexadores Coluna Venda
		StringGrid3->Cells[0][0] = "PRODUTO";
		StringGrid3->Cells[1][0] = "PREÇO UNITÁRIO";
		StringGrid3->Cells[2][0] = "QUANTIDADE";
		StringGrid3->Cells[3][0] = "TOTAL";
	}

	 ComboBox1->Clear();
     // Atualizar o ComboBox com os nomes dos clientes cadastrados
	 ComboBox1->Items->Clear();
	 for (size_t i = 0; i < clientes.size(); i++)
	 {
		ComboBox1->Items->Add(clientes[i].getNome()); // Adiciona o nome do cliente no ComboBox
	 }

	 ComboBox2->Clear();
     // Atualizar o ComboBox com os nomes dos produtos cadastrados
	 ComboBox2->Items->Clear();
	 for (size_t i = 0; i < estoque.size(); i++)
	 {
		ComboBox2->Items->Add(estoque[i].getNome()); // Adiciona o nome do cliente no ComboBox
	 }
}


//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn12Click(TObject *Sender)
{
    this->PageControl1->ActivePageIndex = 4;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn13Click(TObject *Sender)
{
    // Limpa o conteúdo do Edit15
    Edit15->Clear();

	// Reseta a StringGrid para apenas o cabeçalho
	StringGrid4->RowCount = 1; // Apenas uma linha (geralmente usada para cabeçalho)

	// Opcional: Limpa os textos do cabeçalho, se necessário
	for (int col = 0; col < StringGrid4->ColCount; col++)
	{
		// Indexadores Coluna Histórico
		StringGrid4->Cells[0][0] = "PRODUTO";
		StringGrid4->Cells[1][0] = "PREÇO UNITÁRIO";
		StringGrid4->Cells[2][0] = "QUANTIDADE";
		StringGrid4->Cells[3][0] = "TOTAL";
	}

}
//---------------------------------------------------------------------------

