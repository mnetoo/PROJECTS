import { BrowserRouter as Router, Routes, Route } from "react-router-dom";

import Home from "./components/pages/Home";
import Contato from "./components/pages/Contato";
import Empresa from "./components/pages/Empresa";
import NovoProjeto from "./components/pages/NovoProjeto";
import Projetos from "./components/pages/Projetos";

import NavBar from "./components/layout/NavBar";
import Footer from './components/layout/Footer';

import "./App.css";
import Container from "./components/layout/Container";

function App() {
  return (
    <Router>
      <NavBar />
      <Container customClass="min-heigth">
        
        <Routes>
          <Route exact path="/" element={<Home />} />
          <Route exact path="/empresa" element={<Empresa />} />
          <Route exact path="/projetos" element={<Projetos />} />
          <Route exact path="/contato" element={<Contato />} />
          <Route exact path="/novoprojeto" element={<NovoProjeto />} />
        </Routes>
        
      </Container>
      <Footer />
    </Router>
  );
}

export default App;
