import { BrowserRouter as Router, Routes, Route} from 'react-router-dom';
import Home from './components/pages/Home';
import Contato from './components/pages/Contato';
import Empresa from './components/pages/Empresa';
import NavBar from './components/layout/NavBar';
import Footer from './components/layout/Footer';


function App() {

  return (
    <Router>

      <NavBar />
      
      <Routes>
        <Route path="/" element={<Home />} />
        <Route path="/empresa" element={<Empresa />} />
        <Route path="/contato" element={<Contato />} />
      </Routes>
      <Footer />

    </Router>
  );


}

export default App;