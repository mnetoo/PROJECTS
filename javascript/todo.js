const texto = document.querySelector('input');
const btnInsert = document.querySelector('.divInsert button');
const btnDeleteAll = document.querySelector('header button');
const ul = document.querySelector('ul');
const modalAll = document.getElementById('modalAll');
const modalSingle = document.getElementById('modalSingle');
const confirmDeleteAllBtn = document.getElementById('confirmDeleteAll');
const cancelDeleteAllBtn = document.getElementById('cancelDeleteAll');
const confirmDeleteSingleBtn = document.getElementById('confirmDeleteSingle');
const cancelDeleteSingleBtn = document.getElementById('cancelDeleteSingle');

var itensDB = [];
var itemToDelete = null; // Variável para armazenar o índice do item a ser excluído

// Função para mostrar o modal para excluir todas as tarefas
function showModalAll() {
  modalAll.classList.add('show');
}

// Função para mostrar o modal para excluir uma tarefa específica
function showModalSingle(index) {
  itemToDelete = index;  // Armazena o índice do item a ser excluído
  modalSingle.classList.add('show');
}

// Função para esconder o modal
function hideModalAll() {
  modalAll.classList.remove('show');
}

// Função para esconder o modal de uma tarefa específica
function hideModalSingle() {
  modalSingle.classList.remove('show');
}

// Ação ao clicar no botão de excluir todas as tarefas
btnDeleteAll.onclick = () => {
  showModalAll();
}

// Ação de confirmar a exclusão de todas as tarefas
confirmDeleteAllBtn.onclick = () => {
  itensDB = [];
  updateDB();
  hideModalAll();
}

// Ação de cancelar a exclusão de todas as tarefas
cancelDeleteAllBtn.onclick = () => {
  hideModalAll();
}

texto.addEventListener('keypress', e => {
  if (e.key == 'Enter' && texto.value != '') {
    setItemDB();
  }
});

btnInsert.onclick = () => {
  if (texto.value != '') {
    setItemDB();
  }
}

function setItemDB() {
  if (itensDB.length >= 20) {
    alert('Limite máximo de 20 itens atingido!');
    return;
  }

  itensDB.push({ 'item': texto.value, 'status': '' });
  updateDB();
}

function updateDB() {
  localStorage.setItem('todolist', JSON.stringify(itensDB));
  loadItens();
}

function loadItens() {
  ul.innerHTML = "";
  itensDB = JSON.parse(localStorage.getItem('todolist')) ?? [];
  itensDB.forEach((item, i) => {
    insertItemTela(item.item, item.status, i);
  });
}

function insertItemTela(text, status, i) {
  const li = document.createElement('li');
  
  li.innerHTML = `
    <div class="divLi">
      <input type="checkbox" ${status ? 'checked' : ''} data-i=${i} onchange="done(this, ${i});" />
      <span data-si=${i}>${text}</span>
      <button onclick="showModalSingle(${i})" data-i=${i}><i class='bx bx-trash'></i></button>
    </div>
  `;
  ul.appendChild(li);

  const span = document.querySelector(`[data-si="${i}"]`);
  if (status) {
    span.classList.add('line-through');
  } else {
    span.classList.remove('line-through');
  }

  texto.value = ''; // Limpar o campo de texto após inserir
}

function done(chk, i) {
  if (chk.checked) {
    itensDB[i].status = 'checked';
  } else {
    itensDB[i].status = '';
  }

  updateDB();
}

function removeItem() {
  if (itemToDelete !== null) {
    itensDB.splice(itemToDelete, 1);
    updateDB();
    hideModalSingle();
  }
}

confirmDeleteSingleBtn.onclick = removeItem;

cancelDeleteSingleBtn.onclick = () => {
  hideModalSingle();
}

loadItens();

// Animação botão Add
document.addEventListener("DOMContentLoaded", function () {
  const btn = document.querySelector(".bx-plus");

  btn.addEventListener("click", function () {
    btn.classList.add("rotate");

    setTimeout(() => {
      btn.classList.remove("rotate");
    }, 800); // Tempo igual ao da animação (0.8s)
  });
});