var editor = ace.edit("editor");
editor.setTheme("ace/theme/tomorrow_night_eighties");
editor.session.setMode("ace/mode/c_cpp");
var data;
function extract_error_lines(data){
  console.log(data);
  var i = 0;
  var len = data.length;
  for(i = 0;i < len - 3;i++){
    if(isFinite(data[i]) && isFinite(data[i+2]) && data[i]!=" " && data[i+2]!=" "){
      //console.log(data[i]+" "+data[i+2]);
      editor.getSession().setAnnotations([{
        row: parseInt(data[i])-1,
        text: "Error Detected",
        type: "error" // also warning and information
      }]);
    }
  }
}
function run_code(){
  var code = editor.getSession().getValue();
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if(this.readyState == 4 && this.status == 200){
      data = xhttp.responseText;
      document.getElementById("compiler_output").innerHTML = "<pre>"+data+"</pre>";
      extract_error_lines(data);

    }
  };
  xhttp.open("POST","/run",true);
  xhttp.setRequestHeader("Content-type","application/x-www-form-urlencoded");
  xhttp.send("code="+code);
}
