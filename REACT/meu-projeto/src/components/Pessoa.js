function Pessoa ({foto, nome, idade, profissao}) {
    return (
        <div>
            <img src={foto} alt={nome}/>
            <h4>Nome: {nome}</h4>
            <p>Idade: {idade}</p>
            <p>Profissão: {profissao}</p>
        </div>
    )
}

export default Pessoa