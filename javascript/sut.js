Date.prototype.getDaySeconds = function getDaySeconds() {
	return (this.getUTCHours()* 60 + this.getUTCMinutes())*60 + this.getUTCSeconds() + this.getUTCMilliseconds()/1000;
}

Date.prototype.getDaySimpleSeconds = function getDaySimpleSeconds() {
	return Math.floor(this.getDaySeconds()/ (24*60*60) * (10*100*100));
}

Date.prototype.getSimpleMilliseconds = function getSimpleMilliseconds() {
	return (this.getDaySeconds()/ (24*60*60) * (10*100*100)) - this.getDaySimpleSeconds();
}

Date.prototype.getSimpleSeconds = function getSimpleSeconds() {
  var ss_ofs = this.getDaySimpleSeconds();
  var sm_ofs = Math.floor(ss_ofs/100);
  var sh_ofs = Math.floor(sm_ofs/100);
  
  return ss_ofs - sm_ofs*100;
}

Date.prototype.getSimpleMinutes = function getSimpleMinutes() {
  var ss_ofs = this.getDaySimpleSeconds();
  var sm_ofs = Math.floor(ss_ofs/100);
  var sh_ofs = Math.floor(sm_ofs/100);
  
  return sm_ofs-sh_ofs*100;
}

Date.prototype.getSimpleHours = function getSimpleHours() {
  var ss_ofs = this.getDaySimpleSeconds();
  var sm_ofs = Math.floor(ss_ofs/100);
  var sh_ofs = Math.floor(sm_ofs/100);
  
  return sh_ofs;
}

Date.prototype.toSUTTimeString = function toSUTTimeString() {

  var now = this.getUTCHours ? this : arguments[0];
  
  if (!now || !now.getSimpleHours || !now.getSimpleMinutes || !now.getSimpleSeconds)
    throw new Error("Invalid argument: this or arg[0] must be a date object");

  return ('0' + now.getSimpleHours()).slice(-2) + ':' + ('0'  + now.getSimpleMinutes()).slice(-2) + ':' + ('0' + now.getSimpleSeconds()).slice(-2) + " SUT";
}

Date.prototype.toSUTString = function toSUTString() {
  var now = this.toDateString ? this : arguments[0];
  
  if (!now || !now.toDateString || !now.toSUTTimeString)
    throw new Error("Invalid argument: this or arg[0] must be a date object");

  return now.toDateString() + ' ' + now.toSUTTimeString();
}