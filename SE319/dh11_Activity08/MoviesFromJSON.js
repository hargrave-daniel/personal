fetch('MoviesFromJSON.json')
    .then(response => response.json())
    .then(data => {
        const movies = data.movies;
        loadMovies(movies); // Call loadMovies to display the movies
    })
    .catch(error => console.error('Error fetching or parsing JSON:', error));
function loadMovies(myMovies) {
    var mainContainer = document.getElementById("goodmovies");

    for (let i = 0; i < myMovies.length; i++) {
        let movie = myMovies[i];
        let div = document.createElement("div");
        div.innerHTML = `
            <h2>${movie.title}</h2>
            <p>${movie.year}</p>
            <img src="${movie.url}" alt="${movie.title} Poster" style="max-width: 200px;">
            `;
        mainContainer.appendChild(div);
    }
} // end of function loadMovies

