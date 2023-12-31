<?php
require_once("business.php");
require_once("image-utils.php");

function cats(&$model){
    return '/cats';
}

function upload(&$model){
    if($_SERVER['REQUEST_METHOD'] === 'POST' && isset($_FILES['file'])){
        $result = handle_image_upload();
        return $result;
    }
    else{
        return '/upload';
    }
}

function galeria(&$model){
    $cats = get_pictures();
    $model['cats'] = $cats;
    return '/galeria';
}

function index(&$model){
    return '/index';
}

function laplace_transform(&$model){
    return '/translapl';
}

function uni(&$model){
    return '/cats/uni';
}

function panko(&$model){
    return '/cats/panko';
}

function melonandfin(&$model){
    return '/cats/melonandfin';
}

function viewimage(&$model)
{
    $model['id'] = $_GET['id'];
    return '/viewimage';
}