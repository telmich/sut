Date.prototype.toSUTTimeString = function toSUTTimeString() {


  var now = this.getUTCHours ? this : arguments[0];
  
  if (!now || !now.getUTCHours || !now.getUTCMinutes || !now.getUTCSeconds || !now.getUTCMilliseconds)
    throw new Error("Invalid argument: this or arg[0] must be a date object");
    
  var ss_ofs = ( (now.getUTCHours()* 60 + now.getUTCMinutes())*60 + now.getUTCSeconds() + now.getUTCMilliseconds()/1000) / (24*60*60) * (10*100*100);
  var sm_ofs = Math.floor(ss_ofs/100);
  var sh_ofs = Math.floor(sm_ofs/100);
  
  return ('0' + sh_ofs).slice(-2) + ':' + ('0' + (sm_ofs-sh_ofs*100)).slice(-2) + ':' + ('0' + Math.round(ss_ofs - sm_ofs*100)).slice(-2) + " SUT";
}

Date.prototype.toSUTString = function toSUTString() {
  var now = this.toDateString ? this : arguments[0];
  
  if (!now || !now.toDateString || !now.toSUTTimeString)
    throw new Error("Invalid argument: this or arg[0] must be a date object");

  return now.toDateString() + ' ' + now.toSUTTimeString();
}