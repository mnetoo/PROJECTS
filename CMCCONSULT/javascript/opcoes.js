function setupButtonNavigation(buttonId, targetUrl) {
    const button = document.getElementById(buttonId);
    if (button) {
        button.addEventListener('click', function() {
            window.location.href = targetUrl; // Abre a URL na mesma aba
        });
    } else {
        console.error(`Button with id ${buttonId} not found.`);
    }
}

setupButtonNavigation('NP', '../checklist/novoPublico.html');
setupButtonNavigation('NI', '../checklist/novoINSS.html');
setupButtonNavigation('PP', '../checklist/portPublico.html');
setupButtonNavigation('PI', '../checklist/portINSS.html');
setupButtonNavigation('LS', '../checklist/LiquidSimult.html');
setupButtonNavigation('CD', '../checklist/compraDivida.html');