function imprimirPagina() {
    window.print();
}

//====================================================================================================

function removeMask(input) {
    // Remove a formatação ao focar
    input.value = input.value.replace('R$ ', '').replace('.', '').replace(',', '.');
}

function applyMask(input) {
    let valor = parseFloat(input.value.replace('R$ ', '').replace('.', '').replace(',', '.'));
    if (!isNaN(valor)) {
        // Converte para o formato de moeda (R$)
        input.value = 'R$ ' + valor.toLocaleString('pt-BR', { minimumFractionDigits: 2, maximumFractionDigits: 2 });
    } else {
        // Caso o valor não seja válido, não altera o input
        input.value = '';
    }
}

//====================================================================================================

function updateLibCliente() {
    // Obtém os valores dos inputs e remove a formatação de R$
    let liquidCont = parseFloat(removeFormatting(document.getElementById("liquid_cont").value)) || 0;
    let amparo = parseFloat(removeFormatting(document.getElementById("amparo").value)) || 0;
    let vida = parseFloat(removeFormatting(document.getElementById("vida").value)) || 0;
    let seguro = parseFloat(removeFormatting(document.getElementById("seguro").value)) || 0;

    // Calcula o valor de lib_cliente
    let libCliente = liquidCont - (amparo + vida + seguro);
    
    // Atualiza o input lib_cliente com formatação R$
    document.getElementById("lib_cliente").value = formatCurrency(libCliente);
}

function removeFormatting(value) {
    // Remove 'R$ ', pontos e comas para converter corretamente em número
    return value.replace('R$ ', '').replace(/\./g, '').replace(',', '.').trim();
}

function formatCurrency(value) {
    // Formata o valor como R$
    return 'R$ ' + parseFloat(value).toLocaleString('pt-BR', { minimumFractionDigits: 2, maximumFractionDigits: 2 });
}

//====================================================================================================

function fillCurrentDate() {
    // Cria uma nova data
    const today = new Date();
    
    // Formata a data no formato YYYY-MM-DD
    const year = today.getFullYear();
    const month = String(today.getMonth() + 1).padStart(2, '0'); // Mês começa do 0
    const day = String(today.getDate()).padStart(2, '0');
    
    // Cria a data no formato YYYY-MM-DD
    const formattedDate = `${year}-${month}-${day}`;
    
    // Preenche o input com a data formatada
    document.getElementById("data").value = formattedDate;
}

// Chama a função ao carregar a página
window.onload = fillCurrentDate;

//====================================================================================================

function calcularParcelasRestantes() {
    const pagas = parseInt(document.getElementById("parcela_pagas").value) || 0;
    const original = parseInt(document.getElementById("parcela_original").value) || 0;
    const restantes = original - pagas;
    
    document.getElementById("parcela_restantes").value = restantes >= 0 ? restantes : 0;
}

//====================================================================================================

// Chama o JSON para opções de universidades
fetch('../json/agencias.json')
    .then(response => response.json())
    .then(data => {
        const select = document.getElementById('agencia');
        data.forEach(agencia => {
            const option = document.createElement('option');
            option.value = agencia.id;  // Define o valor do campo option com o ID
            option.textContent = agencia.agencia;  // Exibe o nome da instituição
            select.appendChild(option);
        });
    })
    .catch(error => console.error('Erro ao carregar o arquivo JSON:', error));