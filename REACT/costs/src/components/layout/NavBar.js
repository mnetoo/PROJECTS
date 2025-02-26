import { Link } from "react-router-dom";
import styles from "./NavBar.module.css";
import Container from "./Container";
import logo from "../../img/costs_logo.png";

function NavBar() {
  return (
    <nav className={styles.navbar}>
      <Container>

        <Link exact to="/"> <img src={logo} alt="costs" /> </Link>
        
        <ul className={styles.list}>

          <li>
            <Link exact to="/" className={styles.item}>Home</Link>
          </li>

          <li>
            <Link exact to="/projetos" className={styles.item}>Projetos</Link>
          </li>

          <li>
            <Link exact to="/empresa" className={styles.item}>Empresa</Link>
          </li>

          <li>
            <Link exact to="/contato" className={styles.item}>Contato</Link>
          </li>
          
        </ul>
      </Container>
    </nav>
  );
}

export default NavBar;