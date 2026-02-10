let movieName = document.forms["my_form"]["inputMovieName"];
let inputMovieName = movieName.value;

function getInputValue() {
  movieName = document.forms["my_form"]["inputMovieName"];
  inputMovieName = movieName.value;

  fetch("./MoviesFromJSON.json")
    .then(response => response.json())
    .then(myMovies => loadMovies(myMovies))
    .catch(error => console.error('Error:', error));
}

function loadMovies(myMovies) {
  var mainContainer = document.getElementById("goodmovies");
  mainContainer.innerHTML = ""; 

  for (var i = 0; i < myMovies.movies.length; i++) {
    if (myMovies.movies[i].title === inputMovieName) {
      let movieDiv = document.createElement("div");
      movieDiv.innerHTML = `
        <h2>${myMovies.movies[i].title}</h2>
        <p>Year: ${myMovies.movies[i].year}</p>
        <img src="${myMovies.movies[i].url}" alt="${myMovies.movies[i].title}" style="max-width: 200px;">
      `;
      mainContainer.appendChild(movieDiv);
    }
  }
}
