function Saudacao ({nome}) {

    function gerarSaudacao (algumNome) {
        return `Olá, ${algumNome}!`;
    }

    return (
    <>
        <p>{nome && gerarSaudacao(nome)}</p>
    </>
    )
}

export default Saudacao;