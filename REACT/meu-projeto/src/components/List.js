import Item from './Item'

function List () {
    return (
        <>
            <h4>Minha Lista</h4>
            <ul>
                <Item marca="Ferrari" ano_lancamento={1985}/>
                <Item marca="Audi" ano_lancamento={1986}/>
                <Item />
            </ul>
        </>

    )
}

export default List