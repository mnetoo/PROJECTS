import { Link } from "react-router-dom";
import styles from "./NavBar.module.css";

function NavBar() {
  return (
    <ul className={styles.list}>
      <li>
        <Link exact to="/" className={styles.item} >Home</Link>
      </li>
      <li>
        <Link to="/empresa" className={styles.item} >Empresa</Link>
      </li>
      <li>
        <Link to="/contato" className={styles.item} >Contato</Link>
      </li>
    </ul>
  );
}

export default NavBar;
