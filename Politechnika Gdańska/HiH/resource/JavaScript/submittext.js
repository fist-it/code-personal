document.addEventListener("DOMContentLoaded", function () {
  var bugForm = document.getElementById("bugForm");
  var confirmationMessage = document.getElementById("confirmationMessage");
  var submitted = sessionStorage.getItem("bugdesc");
  console.log("DOMloaded");
  if (submitted) {
    console.log("submitted != null");
    bugForm.style.display = "none";
    confirmationMessage.style.display = "block";
    confirmationMessage.innerHTML =
      "Dziękuję za zgłoszenie błędu: " + submitted;
  } else {
    console.log("submitted == null");
    //bugForm.addEventListener("submit", e);
  }
});

function e(event) {
  console.log("clicked");
  var bugDescription = bugForm.querySelector('input[name="bug"]').value;
  confirmationMessage.innerHTML =
    "Dziękuję za zgłoszenie błędu: " + bugDescription;
  confirmationMessage.style.display = "block";
  sessionStorage.setItem("bugdesc", bugDescription);
  bugForm.style.display = "none";
}
